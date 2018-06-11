#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid;

	pid = fork();

	if(pid == 0)
	{
		printf("child.");
	}
	else
	{
		printf("parent.");
	}
	return 0;
}