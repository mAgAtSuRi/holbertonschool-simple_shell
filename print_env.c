#include "main.h"

int main ()
{
	int i = 0;
	extern char **environ;
	
	while(environ[i] != NULL)
	{
		if (environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T'
		&& environ[i][3] == 'H')
			printf("%s\n", environ[i]);
		i++;
	}

	
	return(0);
}