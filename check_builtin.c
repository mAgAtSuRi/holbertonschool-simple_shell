#include "main.h"
/**
 * _printenv - print the environment
 * @argv: array of arguments from getline and splitstring
 * @path: array of exec directories
 * @status: last error status encountered
 */
void _printenv(char **argv, char **path, int status)
{
	int i = 0;
	(void)status;

	if (environ == NULL)
	{
		clean_all(argv, path);
		exit(EXIT_FAILURE);
	}

	while (environ[i])
		printf("%s\n", environ[i++]);
}

/**
 * frexit - terminates program
 * @argv: array of arguments from getline and splitstring
 * @path: array of exec directories
 * @status: last error status encountered
 */
void frexit(char **argv, char **path, int status)
{
	int arg_code;

	if (argv[1] != NULL && argv[2] != NULL)
	{
		fprintf(stderr, "./prompt: %s: too many arguments\n", argv[0]);
		return;
	}

	if (argv[1] == NULL)
	{
		clean_all(argv, path);
		exit(status);
	}
	else
	{
		arg_code = _atoi(argv[1]);
		clean_all(argv, path);
		exit(arg_code);
	}
}

/**
 * check_builtin - check if the command is a builtin
 * @command: command to check
 * @argv: array of arguments from getline and splitstring
 * @path: array of exec directories
 * @status: last error status encountered
 *
 * Return: 1 if builtin otherwise 0;
 */
int check_builtin(char *command, char **argv, char **path, int status)
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
			build_in[i].f(argv, path, status);
			return (1);
		}
		i++;
	}

	return (0);
}
