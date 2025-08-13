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

typedef struct commands
{
	char *cmd;
	/* type ? (*f)(args ?)*/
} commands_t;

char **split_string(char *str, const char *sep);
char **get_paths(char **environ);
char *check_path(char **path, char *exec_name);

#endif
