#include "main.h"
/**
 * clean_all - free everything
 * @line: line to free
 * @argv: argv to free
 * @path: path to free
 */
void clean_all(char *line, char **argv, char **path)
{
	if (line != NULL)
		free(line);
	free_array(argv);
	free_array(path);
}
