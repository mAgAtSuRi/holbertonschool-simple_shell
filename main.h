#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <linux/limits.h>
/**
 * struct built_in - Structure of a shell command
 * @cmd: builtin command
 * @f: pointer to function associated with the command
 *
 * Description: Associate builtin command with its function
 */
typedef struct built_in
{
	char *cmd;
	void (*f)(char **, char*, char **);
} builtin_t;

char **split_string(char *str, const char *sep);
char **get_paths(char **environ);
char *check_path(char **path, char *exec_name);
int check_builtin(char *command, char **argv, char *line, char **path);
int _atoi(char *str);
void frexit(char **argv, char *line, char **path);
void _printenv(char **argv, char *line, char **path);
void free_array(char **array);
void clean_all (char *, char **, char **);

#endif
