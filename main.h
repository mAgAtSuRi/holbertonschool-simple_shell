#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

typedef struct commands
{
	char *cmd;
	/* type ? (*f)(args ?)*/
} commands_t;

char **split_string(char *);
#endif
