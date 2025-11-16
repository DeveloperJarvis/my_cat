# MY CAT

Minor project for writing **cat** like code

### Install GCC

For Ubuntu:

```bash
sudo apt install gcc -y
```

## Compile using gcc

```bash
gcc -g -Wall -Wextra -o my_cat.out my_cat.c
```

## Execute the object file

1. Simple execute

```bash
# ./my_cat.out
./my_cat.out
# ./my_cat.out <file name>
./my_cat.out first.txt
# ./my_cat.out <first file name> <second file name>
./my_cat.out first.txt second.txt
```

## For Windows:

**NOTE** Clang will throw error for fopen is deprecated

### Install clang

1. Install Microsoft Visual Studio
2. Add to your windows path:
3. Win+ R > sysdm.cpl
4. Advanced > Environment Variables
5. System variables > Path > Edit
6. Add (C:\Program Files\Microsoft Visual Studio\18\<Version>\VC\Tools\Llvm\bin
   )

### Compile using gcc

```bash
clang -c my_cat.c -o my_cat.o
clang my_cat.o -o my_cat_x64.exe
```

### Execute the object file

1. Simple execute

```bash
# my_cat_x64.exe
my_cat_x64.exe
# my_cat_x64.exe <file name>
my_cat_x64.exe first.txt
# my_cat_x64.exe <first file name> <second file name>
my_cat_x64.exe first.txt second.txt
```

## Creating tag

```bash
# 1. Check existing tags
git tag
# 2. Create a valid tag
git tag -a v1.0.0 -m "Release version 1.0.0"
# or lightweight tag
git tag v1.0.0
# push tag to remote
git push origin v1.0.0
```
