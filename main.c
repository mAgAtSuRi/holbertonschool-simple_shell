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
		/*Don't forget to free getline*/
		if (nread == -1)
			break;
		if (nread == 1)/*cas où c'est un espace ; ignorer ?*/
			continue;
		if ((nread > 0) && (line[nread - 1] == '\n'))
			line[nread - 1] = '\0'; /*raison pour laquelle ça foire avec echo ?*/

		argv = split_string(line, " ");
		if (argv[0] == NULL)
		{
			free(argv);
			continue;
		}

		if (argv[0][0] != '/')
		{
			if (check_builtin(argv[0], argv) == 1)
				continue;

			temp_cmd = check_path(path, argv[0]);
			if (temp_cmd == NULL)
			{
				fprintf(stderr, "%s: command not found\n", argv[0]);
				free(argv);
				continue;
			}
		}
		argv[0] = temp_cmd;/*attention, hors if !
							temp_cmd non alloué si la cmd
							commence par un / */

		fpid = fork();
		if (fpid == -1)
		{
			perror("fpid");
			exit(EXIT_FAILURE); /*préciser*/
		}
		else if (fpid == 0) /*enfant*/
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./prompt");
				exit(EXIT_FAILURE); /*préciser*/
			}
		}
		else
			waitpid(fpid, NULL, 0);
	}

	return (0);
}
