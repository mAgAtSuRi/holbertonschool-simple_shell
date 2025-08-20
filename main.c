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
	pid_t fpid;
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
		/*nread = getline(&line, &len, stdin);
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
		}*/

		if (strchr(argv[0], '/'))
		{
			if (access(argv[0], X_OK) != 0)
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
				free_array(argv);
				continue;
			}
		}
		else
		{
			if (check_builtin(argv[0], argv, path, status) == 1)
			{
				free_array(argv);
				continue;
			}

			temp_cmd = check_path(path, argv[0]);
			if (temp_cmd == NULL)
			{
            	fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        		clean_all(argv, path);
            	exit(127);
			}
			free(argv[0]);
			argv[0] = temp_cmd;
		}

		fpid = fork();
		if (fpid == -1)
		{
			perror("fpid");
			clean_all(argv, path);
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
	free_array(path);
	return (0);
}
