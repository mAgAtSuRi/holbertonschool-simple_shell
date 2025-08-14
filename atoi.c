#include "main.h"
#include <limits.h>

/**
 * _atoi - convert string to int
 * @s: string to convert
 *
 * Return: the string converted in integer
 */
int _atoi(char *s)
{
	int i = 0;
	int tmp = 0;
	int neg = 0;

	while (s[i] != '\0')
	{
		if (s[i] == 45)
			neg++;
		if (s[i] >= 48 && s[i] <= 57)
		{
			if (tmp > (INT_MAX - s[i] + 48) / 10)
			{
				if (neg % 2 == 0)
					return (INT_MAX);
				else
					return (INT_MIN);
			}
			tmp = tmp * 10 + (s[i] - 48);
			if (s[i + 1] < 48 || s[i + 1] > 57)
				break;
		}
		i++;
	}
	if (tmp == 0)
		return (0);
	if (neg % 2 != 0)
		tmp = -tmp;
	return (tmp);
}
