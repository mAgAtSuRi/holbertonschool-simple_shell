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
