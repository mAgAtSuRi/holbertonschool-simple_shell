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

	path = get_paths(environ);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("prompt$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		if (nread == 1)/*cas où c'est un espace ; ignorer ?*/
			continue;
		if ((nread > 0) && (line[nread - 1] == '\n'))
			line[nread - 1] = '\0'; /*raison pour laquelle ça foire avec echo ?*/

		argv = split_string(line, " ");
		if (argv[0] == NULL)
		{
			free_array(argv);
			continue;
		}

		if (argv[0][0] != '/')
		{
			if (check_builtin(argv[0], argv) == 1)
			{
				free_array(argv);
				continue;
			}

			temp_cmd = check_path(path, argv[0]);
			if (temp_cmd == NULL)
			{
				fprintf(stderr, "%s: command not found\n", argv[0]);
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
				perror("./prompt");
				free(line);
				free_array(argv);
				free_array(path);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(fpid, NULL, 0);
			free_array(argv);
		}
	}
	free(line);
	free_array(path);
	return (0);
}
