#include "main.h"
/**
 * _printenv - print the environment
 * @argv: array of arguments from getline and splitstring
 */
void _printenv(char **argv, char *line, char **path)
{
	extern char **environ;
	int i = 0;

	if (environ == NULL)
	{
		clean_all(line, argv, path);
		exit(EXIT_FAILURE);
	}

	while (environ[i])
		printf("%s\n", environ[i++]);
}

/**
 * frexit - terminates program
 * @argv: array of arguments from getline and splitstring
 */
void frexit(char **argv, char* line, char **path)
{
	if (argv[1] != NULL && argv[2] != NULL)
	{
		fprintf(stderr, "./prompt: %s: too many arguments\n", argv[0]);
		return;
	}

	if (argv[1] == NULL)
	{
		clean_all(line, argv, path);
		exit(0);
	}
	else
	{
		clean_all(line, argv, path);
		exit(_atoi(argv[1]));
	}
}

/**
 * check_builtin - check if the command is a builtin
 * @command: command to check
 * @argv: array of arguments from getline and splitstring
 *
 * Return: 1 if builtin otherwise 0;
 */
int check_builtin(char *command, char **argv, char *line, char **path)
{
	int i = 0;
	builtin_t build_in[] = {
		{"exit", frexit},
		{"env", _printenv},
		{NULL, NULL},
	};

	while (build_in[i].cmd)
	{
		if (strcmp(command, build_in[i].cmd) == 0)
		{
			build_in[i].f(argv, line, path);
			return (1);
		}
		i++;
	}

	return (0);
}
