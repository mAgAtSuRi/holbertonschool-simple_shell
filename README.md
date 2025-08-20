# HSH - Holbertonschool Simple shell

This project was about programming a simple shell.  
Once executed, this program prints a prompt and wait for the user to type commands.  
This simple shell handle executable paths such as /bin/ls, as well as commands like "ls" with and without arguments.  
It can be used in non-interactive way.  

This Simple shell is coded with C language. 

## 🧰 Requirements :

**Installation and compilation**

This simple shell was developped on Ubuntu.  
To run this program, all .c files in this repository must be compiled together. Make sure you have GCC compiler installed on your device.  

In order to get the executable file, use the following line of command :

> gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

For your consideration, here are some explanations about flags used in gcc command :

- `-Wall` : every warnings are displayed, allows you to identify problems in code
- `-Werror`: warnings are treated as errors. You won't be able to compile if any warning appears.
- `-Wextra`: more warnings (not included in Wall) are displayed
- `-pedantic` : compiler will generate warnings if code don't respect C standards
- `-std=gnu89` : compiler will use C89 standard
- `*.c` : all files ending by ".c" in the current directory will be compiled
- `-o hsh`: executable name will be "hsh  

Here is a brief description of each files needed : 
| File name 	| Description |
|---------------|-------------|
|`main.c`		| contains the starting points of the program.
|`getpath.c`	| is a function that reads the PATH variable and stores its directories in an array; required to find executable files
|`checkpath.c`	| is a function that check if command line typed in stdin can be found in PATH variable.
|`check_builtin.c`| is a function that check if command line typed in stdin is a built-in command.
|`split_string.c`| is a function that use `strtok` function to deal with arguments of the command, but also used in getpath.
|`atoi.c`		| since using the standard atoi was not allowed, we implemented our own version.
|`main.h`	| is our header file, needed to the compiler.  
|`man`	| contains the man page of the program

**Authorized functions :**  

Here is the list of functions we were authorized to use : 
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
Once compilation is done, use the following command to start the shell :
> ./hsh

Then, a prompt appears and waits for the user to type commands. You can use :
- An executable pathname : for example `/bin/ls`
- A command line : for example `ls`

### End the program
Once you want to leave the simple shell, you can type :
> exit

or press `ctrl + D`

### Examples of uses
Here are some example of use :
> prompt$ /bin/ls  
README.md  atoi.c  check_builtin.c  clean_all.c  free_array.c  hsh  main.c  main.h  path.c  printenv  printpath  prompt  split_string.c  
prompt$

> prompt$ ls  
README.md  atoi.c  check_builtin.c  clean_all.c  free_array.c  hsh  main.c  main.h  path.c  printenv  printpath  prompt  split_string.c  
prompt$

You can also use the program in a non-interactive way, while in your Linux Shell :
> <path_directory>$ echo "ls" | ./hsh  
README.md  atoi.c  check_builtin.c  clean_all.c  free_array.c  hsh  main.c  main.h  path.c  printenv  printpath  prompt  split_string.c

**Only `env` and `exit` works for built-in commands**

## 🧮 Returns et error messages :
### Returns

The program returns 0 when no problem occurs. 

Here is a recap of all created functions returns :
| Function name | Operation | Returns | Error status code |
|--------------------|---------|------|-------------|
|_atoi	| Convert a string in to and int | The number converted from a string | /
|_printenv | Print environment variables (Built in) | Void | EXIT_FAILURE
|frexit	| Exit the program (Built-in) | Void | If no arguments are given, exit code will 0 or the last error code that occured. If args are given, status code will be the specified number.
|clean_all | Free all the allocated memory | Void | / |
|free_array | Free an array | Void | / |
|get_paths | Store paths stored in PATH variable | Pointer to an array of strings or NULL if malloc fails or if PATH is an empty string| EXIT_FAILURE if environ is NULL
|check_path | Look into PATH directories for an executable file matching the user's command | Pointer to the path of the executable file, or NULL if Malloc fails, PATH is NULL or no match found | /
| split_string | Cut a string using a specific separator and stores the results in a NULL terminated array | Pointer to the array containing the sub-strings or NULL if the string given is NULL or Malloc fails | / 
|get_line | store line typed by user from stdin, and args in an array | 1 if succeed, -1 if getline fails, 0 if split_string fails or command is an empty string | /
| go_process | create a subprocess and use execve to execute the command's binary file | Void | EXIT_FAILURE if subprocess fails to be created, exit(127) if execve fails |
main | run the sell ; instructions to check if user send à pathname or a command, instructions to check is command is a build in and instructions to find binary file in PATH directories are here | 0 if program succeed | exit

### Exit code from main

If no match is found between PATH and user's command, the program exit with a status code = 127.

### Error messages

---
> ./hsh: 1: <some_command> : not found  

Case 1 - The built in command is not implemented yet : you've tried a built in that is not `env`or `exit`. Only `env` and `exit`are implemented yet.

Case 2 - The command does not exist :  you've tried a path or a command that does not exist. 

Case 3 - The command exists but the executable file can't be reached. Here are some possible reasons :
- the external program you are trying to call for is not installed
- the binary file you want to execute is corrupted
- permission to execute the binary file is denied
- your PATH variable has been modified and does not contain the path to your executable.

## 🔎 Flowchart :  
This flowchat explains how the shell works. 

[INSERT]


## 📗 Man page :

If you need help, you can access the man page using this command :
> man man

## 💼 Authors :
**Mathieu Majérus** - https://github.com/MathieuMjr  
**Tristan Martinez** - https://github.com/mAgAtSuRi

