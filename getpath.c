#include "main.h"

/**
 * get_paths - create an array containing pointers path directories
 * @environ: array with pointers to global environment variables
 *
 * Return: An array containing pointers to path directories
 */
char **get_paths(char **environ)
{
	int i = 0, j = 0;
	char **path;
	char *temp_path;
	char *temp_path2;

	
	while(environ[i] != NULL)
	{
		if (environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T'
		&& environ[i][3] == 'H')
			temp_path = environ[i];
		i++;
	}
	temp_path2 = &temp_path[5];
	path = split_string(temp_path2, ":");

	while(path[j] != NULL)
	{
		printf("%s\n",path[j]);
		j++;
	}
	return(path);
}
