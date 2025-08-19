#include "main.h"

/**
 * main - entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL, *temp_cmd;
	size_t len = 0;
	int nread = 0;
	extern char **environ;
	char **argv, **path;
	pid_t fpid;
	int status;

	path = get_paths(environ);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("prompt$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		if (nread == 1)
			continue;
		if ((nread > 0) && (line[nread - 1] == '\n'))
			line[nread - 1] = '\0';

		argv = split_string(line, " ");
		if (argv[0] == NULL)
		{
			free_array(argv);
			continue;
		}

		if (access(argv[0], X_OK) != 0)
		{
			if (check_builtin(argv[0], argv) == 1)
			{
				free_array(argv);
				continue;
			}

			path = get_paths(environ);
			temp_cmd = check_path(path, argv[0]);
			if (temp_cmd == NULL)
			{
                fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
                free_array(argv);
                continue;
			}
			free(argv[0]);
			argv[0] = temp_cmd;
		}

		fpid = fork();
		if (fpid == -1)
		{
			perror("fpid");
			free(line);
			free_array(argv);
			free_array(path);
			exit(EXIT_FAILURE);
		}
		else if (fpid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
				exit(127);
			}
		}
		else
		{
            waitpid(fpid, &status, 0);
            if (WIFEXITED(status))
                status = WEXITSTATUS(status);
            free_array(argv);
        }
	}
	free(line);
	free_array(path);
	return (0);
}
