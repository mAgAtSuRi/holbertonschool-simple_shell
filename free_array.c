#include "main.h"

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
