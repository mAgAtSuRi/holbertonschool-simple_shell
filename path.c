#include "main.h"

/**
 * check_path - check the command path
 * @path: path to check
 * @exec_name: name of the exec to find
 *
 * Return: the complete path
 */
char *check_path(char **path, char *exec_name)
{
	int i = 0;
	DIR *dir;
	struct dirent *file;
	char *buffer;

	buffer = malloc(sizeof(char) * PATH_MAX);
	if (buffer == NULL)
		return (NULL);

	while (path[i])
	{
		dir = opendir(path[i]);
		if (dir == NULL)
		{
			i++;
			continue;
		}

		while ((file = readdir(dir)) != NULL)
		{
			if (strcmp(file->d_name, exec_name) == 0)
			{
				sprintf(buffer, "%s/%s", path[i], exec_name);
				closedir(dir);
				return (buffer);
			}
		}
		closedir(dir);
		i++;
	}

	free(buffer);
	return (NULL);
}


/**
 * get_paths - create an array containing pointers path directories
 * @environ: array with pointers to global environment variables
 *
 * Return: An array containing pointers to path directories
 */
char **get_paths(char **environ)
{
	int i = 0;
	char **path;
	char *temp_path;
	char *temp_path2;

	if (environ == NULL)
		exit(EXIT_FAILURE);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			temp_path = environ[i];
		i++;
	}
	temp_path2 = &temp_path[5];
	path = split_string(temp_path2, ":");

	/**
	* print le path
	* while (path[j] != NULL)
	* {
	* printf("%s\n", path[j]);
	* j++;
	* }
	*/
	return (path);
}
