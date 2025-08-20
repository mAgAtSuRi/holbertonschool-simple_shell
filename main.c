#include "main.h"

/**
 * main - entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *temp_cmd;
	char **argv = NULL, **path = NULL;
	int status = 0;
	int res_line;

	path = get_paths(environ);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("prompt$ ");

		res_line = get_line(&argv);
		if (res_line == -1)
			break;
		if (res_line == 0)
			continue;
		if (strchr(argv[0], '/'))
		{
			if (access(argv[0], X_OK) != 0)
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
				free_array(argv);
				continue; } }
		else
		{
			if (check_builtin(argv[0], argv, path, status) == 1)
			{free_array(argv);
				continue; }

			temp_cmd = check_path(path, argv[0]);
			if (temp_cmd == NULL)
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
				clean_all(argv, path);
				exit(127); }
			free(argv[0]);
			argv[0] = temp_cmd; }
		go_process(argv, path, &status); }
	free_array(path);
	return (0); }
