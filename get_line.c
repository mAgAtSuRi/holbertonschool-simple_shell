#include "main.h"

/**
 * get_line - wait for the user to type command
 * then store it and its args in argv
 * @argv: will store command name or path and arguments
 * Return: 1 if succeed, -1 if getline fails
 * 0 if split_string fails or line is '\0'
 */
int get_line(char ***argv)
{
	int nread = 0;
	char *line = NULL;
	size_t len = 0;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
		return (-1);
	if (nread == 1)
	{
		free(line);
		return (0);
	}
	if ((nread > 0) && (line[nread - 1] == '\n'))
		line[nread - 1] = '\0';

	*argv = split_string(line, " ");
	if (*argv == NULL || *argv[0] == NULL)
	{
		free_array(*argv);
		return (0);
	}
	free(line);
	return (1);
}
