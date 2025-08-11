#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main ()
{
	char *line = NULL;
	size_t len = 0;
	int nread;
	unsigned int mypid;
	unsigned int ppid;

	while (1)
	{
	ppid = getppid();
	printf("Ppid : %u\n", ppid);
	mypid = getpid();
	printf("My Pid %u\n", mypid);
	printf("prompt$ ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		printf("EOF");
		break;
	}
	}
	return (0);
}