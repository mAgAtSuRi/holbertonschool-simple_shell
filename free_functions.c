#include "main.h"
/**
 * clean_all - free everything
 * @argv: argv to free
 * @path: path to free
 */
void clean_all(char **argv, char **path)
{
	free_array(argv);
	free_array(path);
}


/**
 * free_array - frees a 2d array
 * @array: array to free
 *
 */
void free_array(char **array)
{
	int i = 0;

	if (array == NULL)
		return;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
