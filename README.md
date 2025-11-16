# MY CAT

Minor project for writing **cat** like code

### Install GCC

For Ubuntu:

```bash
sudo apt install gcc -y
```

## Compile using gcc

```bash
gcc -g -Wall -Wextra -o my_echo.out my_echo.c
```

## Execute the object file

1. Simple execute

```bash
./my_echo.out
./my_echo.out -n
./my_echo.out -n Hello World
./my_echo.out Hello World
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
clang -c my_echo.c -o my_echo.o
clang my_echo.o -o my_echo_x64.exe
```

### Execute the object file

1. Simple execute

```bash
# encrypting
my_echo_x64.exe
my_echo_x64.exe -n
my_echo_x64.exe -n Hello World
my_echo_x64.exe Hello World
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
