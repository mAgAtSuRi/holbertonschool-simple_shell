# Holberton School - Simple Shell

This project was about programming a simple shell.  
Once executed, this program prints a prompt and wait for the user to type some commands.  
This simple shell handle path of executable files like /bin/ls, but also commands like "ls" and arguments like ls -la.  
It can be used in non interactive way too.  

This Simple shell is coded with C language. 

## 🧰 Requierements :

**Installation and compilation**

This simple shell had been développed on Ubuntu.  
To run this program, all .c files in this repository must be compiled together. Make sure you got GCC compiler installed on your device.  

In order to get the executable file, use the following line of command :

> gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

For yout consideration, here are some explanations about flags used in gcc command :

- `-Wall` : every warnings are displayed, allows you to identify problems in code
- `-Werror`: warnings are treated as errors. You won't be able to compile if any warning appears.
- `-Wextra`: more warnings (not inclued in Wall) are displayed
- `-pedantic` : compiler will generate warnings if code don't respect C standards
- `-std=gnu89` : compiler will use C89 standard
- `*.c` : all files ending by ".c" in the current directory will be compiled
- `-o hsh`: executable name will be "hsh  

Here are the a brief description of each files needed : 
| File name 	| Description |
|---------------|-------------|
|`main.c`		| contains the starting points of the program.
|`getpath.c`	| is a function that read PATH variable in order and stores directories path in it in a array ; requiered to find executable files.
|`checkpath.c`	| is a function that check if command line typed in stdin can be found in PATH variable.
|`check_builtin.c`| is a function that check if command line typed in stdin is a built-in command.
|`split_string.c`| is a function that use `strtok` function to deal with arguments of the command, but also used in getpath.
|`atoi.c`		| since we were not allowed to use atoi from a library for this project, we have coded one by ourselves. This file is necessary in `check_builtin.c`.
|`main.h`	| is our header file, needed to the compiler.  

**Authorized functions :**  

Here is the list a function we were authorized to work with : 
|	|	|	|	|
|---|---|---|---|
| `access`  | `chdir` 	| `close` | `closedir` | 
|`execve` |`exit` |`_exit` |`fflush` 
|`fork` | `free` |`getcwd` |`getline`
|`getpid` |`isatty` | `kill` | `malloc`
|`open`|`opendir` | `perror` | `printf`
|`fprintf` | `vfprintf` | `sprintf` | `putchar`
|`read` | `readdir` | `signal` |`stat`
|`stat` | `fstat` | `strtok` | `wait`
|` waitpid` | `wait3` | `wait4` | `write`  

And all functions from string.h.

## 💡 How to use it :
### Start the simple shell  
Once compilation is done, use the following command to start using this simple shell :
> ./hsh

Then, a prompt appears and wait for the user to type any command. You can use :
- An executable pathname : for example `/bin/ls`
- A command line : for example `ls`

### Examples of uses
- Only `env`and `exit` works for built-in commands
[CONTINUER]

### Error messages

---
> : command not found  

If you're trying a built-in that is not `env`or `exit`, it means it has not been implemented yet.

If you're trying to used a command line, the executable name have not been found. Please check if it is installed on your device.

---
> Bad address  

It means you wrote an invalid pathname. Please check if the executable file you are looking for is installed on your device. 

### End the program
Once you want to leave the simple shell, you can type :
> exit

or press `ctrl + D`

## 🧮 Returns :

## 🔎 Flowchart :  
This flowchat explain how the simple shell works. 

[INSERT]



## 📗 Man page :

## 💧 Memory leaks :

## 🦋 Bugs :

## 💼 Authors :
**Mathieu Majérus** - https://github.com/MathieuMjr  
**Tristan Martinez** - https://github.com/mAgAtSuRi

