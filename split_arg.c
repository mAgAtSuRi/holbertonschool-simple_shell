#include "main.h"

/**
 * split_string - create an array filled with pointers to each word
 * @str: string to split
 *
 * Return: An array like argv
 */
char **split_string(char *str)
{
	int i = 0, j = 0, word_num = 1;
	char *token;
	char **arg;

	if (str == NULL)
		return (NULL);

	if (str[0] == ' ')
		word_num = 0;

	while (str[i])
	{
		if (str[i + 1] != '\0')
		{
			if (str[i] == ' ' && str[i + 1] != ' ')
				word_num++;
		}
		i++;
	}

	arg = malloc(sizeof(char *) * (word_num + 1));
	if (arg == NULL)
		return (NULL);

	arg[word_num] = NULL;
	token = strtok(str, " ");
	while (token != NULL)
	{
		arg[j] = token;
		j++;
		token = strtok(NULL, " ");
	}

	return (arg);
}
