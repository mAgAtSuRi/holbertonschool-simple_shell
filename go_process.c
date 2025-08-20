
#include "main.h"

/**
 * go_process - create a subprocess to execute
 * a command
 * @argv: array containing exe path and parameters
 * @path: array containing PATH directories, needed
 * to be cleaned
 * @status: error status code
 */
void go_process(char **argv, char **path, int *status)
{
	pid_t fpid;

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
		waitpid(fpid, status, 0);
		if (WIFEXITED(*status))
			*status = WEXITSTATUS(*status);
		free_array(argv);
	}
}
