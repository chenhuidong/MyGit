#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void deal(int s)
{
	int status=0;
	int r = wait(&status);
	printf("recycle success %d, %d.\n", r, WEXITSTATUS(status));
}

int main()
{
	/*
	int pid;

	pid = fork();

	if(pid == 0)
	{
		printf("child.");
		sleep(10);
		exit(88);
	}
	else
	{
		printf("parent.");
		int status=0;
		int r = wait(&status);
		printf("recycle success %d, %d.\n", r, WEXITSTATUS(status));
		sleep(200);

	}
	*/

	int pid;
	pid = fork();

	if(pid == 0)
	{
		printf("child.");
		sleep(10);
		exit(88);
	}
	else
	{
		signal(17/*SIGCHLD*/, deal);
		while(1)
		{
			printf("parent.\n");
			sleep(1);
		}
	}
	return 0;
}