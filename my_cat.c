#include <stdio.h>
#include <string.h>

#if defined(_MSC_VER)
#define FOPEN(fptr, filename, mode) fopen_s(&fptr, filename, mode)
#else
#define FOPEN(fptr, filename, mode) (fptr = fopen(filename, mode))
#endif

// inspired by original cat
void print_help(char *app_name)
{
	printf("Usage: %s [OPTION]... [FILE]...\n", app_name);
	printf("Concatenate FILE(s) to standard output.\n\n");

	printf("With no FILE, or FILE is -, read standard input. \n\n");

	printf("  -A, --show-all			equivalent to -vET\n");
	printf("  -b, --number-nonblank		number nonempty output lines, overrides -");
	printf("  -e,						equivalant to -vE\n");
	printf("  -E, --show-ends			display $ at end of each line\n");
	printf("  -n, --number				number all output lines\n");
	printf("  -s, --squeeze-blank		suppress repeated empty output lines\n");
	printf("  -t,						equivalent to -vT\n");
	printf("  -T, --show-tabs			display TAB characters as ^I\n");
	printf("  -u 						(ignored)\n");
	printf("  -v, --show-nonprinting	use ^ and M- notation, except for LFD and TAB\n\n");

	printf("Examples:\n");
	printf(" %s f - g		Output f's contents, then standard input, then g's contents.\n", app_name);
	printf(" %s		Copy standard input to standard output.\n", app_name);
}

void print_version(char *app_name)
{
	printf("%s 1.0\n", app_name);
	printf("Copyright (C) 2024 Your Name.\n");
	printf("This is free software; see the source for copying conditions.  There is NO\n");
	printf("warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n");
}

// --------- FLAG STATE ---------
int show_ends = 0;		 // -E
int show_tabs = 0;		 // -T
int number_all = 0;		 // -n
int number_nonblank = 0; // -b
int squeeze_blank = 0;	 // -s
int show_nonprint = 0;	 // -v

// --------- helper: print char with -v -----------
void print_v_char(int c)
{
	if (c >= 32 && c < 127) // printable ASCII
		putchar(c);
	else if (c == '\n' || c == '\t') // LF or TAB
		putchar(c);					 // \n & \t untouched (unless -T changes tabs)
	else if (c < 32)				 // control characters: ^A etc
	{
		putchar('^');
		putchar(c + 64); // e.g., 1 -> 'A'
	}
	else if (c == 127) // DEL
	{
		putchar('^');
		putchar('?');
	}
	else if (c > 127) // high ASCII
	{
		putchar('M');
		putchar('-');
		int lower = c - 128;
		print_v_char(lower);
	}
}

// --------- main print handler -----------
// TODO

void cat_stream(FILE *fp)
{
	int c;
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
}

int main(int argc, char *argv[])
{

	// Parse flags
	// TODO: implement flag parsing
	if (argc == 1)
	{
		// No argumnets: read from stdin
		cat_stream(stdin);
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-") == 0)
		{
			// "-" means stdin
			cat_stream(stdin);
			continue;
		}

		FILE *fp;
		FOPEN(fp, argv[i], "rb");
		if (!fp)
		{
			perror(argv[i]);
			continue;
		}

		cat_stream(fp);
		fclose(fp);
	}

	return 0;
}
