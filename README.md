# Simple_Shell

## Objetives

## Instalation
If you want to try our program in your local machine, please follow the next steps:

1. In your local machine clone the next github repository.
```
https://github.com/sebastiancalleu/simple_shell
```
2. Compile the files using this flags.
```
gcc -Wall -Werror -Wextra -pedantic -g *.c *.h -o hsh
```

## Execution
you can run it in interactive mode or non-interactive mode.

1. Run the program with this command for enter in the interactive mode.
```
./hsh
```
2. Try commands that you normally use in the shell like ls or pwd or mkdir.
```
ls
```
3. For close the progam you can type the following command.
```
exit
```
for non-interactive mode:

1. Run the program with this command to use the non-interactive mode.
```
./hsh command_name
```
Where command_name is the command that you want to use, in non-interactive mode the program will close after the command execution.

If you want to check if there is memory leaks in the program run the next command.
```
valgrind ./hsh
```

## Content
In the repository you are going to find the following files, here is a description for every file.

### README.md
this is the readme file that describes this project and how to use it.

### hsh.c
this file contains the main function of the program.

### holberton.h
this file contains the headers used in the program and all the prototypes.

### auxfunctions_1.c
this file contains 5 functions that are for string manipulation, inside the file there is a description for every function.

### auxfunctions_2.c
this file contains 5 functions that are for arguments manipulation, inside the file there is a description for every function.

### auxfunctions_3.c
this file contains 5 functions that are for proccess execution, inside the file there is a description for every function.

### auxfunctions_4.c
this file contains 2 support functions, inside the file there is a description for every function.

## Authors

# Andres Aristizabal
- [Github](https://github.com/aristizabaru)

# Sebastian Calle
- [Github](https://github.com/sebastiancalleu)