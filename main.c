#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main ()
{
	char *line = NULL;
	size_t len = 0;
	int nread = 0;
	extern char **environ;
	char *argv[2];
	pid_t fpid;

	/*commands_t build_in[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL},
	};*/

	while (1)
	{
	if (isatty(STDIN_FILENO) == 1)
		printf("prompt$ ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
		break;
	if (nread == 1 )
		continue;
	if ((nread > 0) && (line[nread - 1] == '\n'))
		line[nread - 1] = '\0';
	argv[0] = line;/*à modifier*/
	argv[1] = NULL;
	fpid = fork();
	if (fpid == -1)
	{
		perror("fpid");
		exit(EXIT_FAILURE); /*préciser*/
	}
	else if (fpid == 0) /*enfant*/
	{	
		if (execve(line, argv, environ) == - 1)
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
