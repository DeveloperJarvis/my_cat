#include <stdio.h>
#include <string.h>


#if defined(_MSC_VER)
#define FOPEN(fptr, filename, mode) fopen_s(&fptr, filename, mode)
#else
#define FOPEN(fptr, filename, mode) (fptr = fopen(filename, mode))
#endif

void cat_stream(FILE *fp)
{
	int c;
	while((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
}

int main(int argc, char* argv[])
{
	//if(argc == 1)
	//{
		// No arguments: read from stdin
	//	printf("Usage: %s <first file> <second file>", argv[0]);
	//}
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
		if(!fp)
		{
			perror(argv[i]);
			continue;
		}

		cat_stream(fp);
		fclose(fp);
	}


	return 0;
}
