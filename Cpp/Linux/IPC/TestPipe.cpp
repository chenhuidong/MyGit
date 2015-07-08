#include "../../MyLinux.h"

int main()
{
	int pipe1[2], pipe2[2];
	pid_t childpid;

	Pipe(pipe1);
	Pipe(pipe2);

	if((childpid = fork()) == 0)
	{
		close(pipe1[1]);
		colse(pipe2[0]);
		server(pipe1[0], pipe2[1]);
		exit(0);
	}

	close(pipe1[0]);
	close(pipe2[1]);

	client(pipe2[0], pipe1[1]);

	waitpid(childpid, NULL, 0);
	return 0;
}