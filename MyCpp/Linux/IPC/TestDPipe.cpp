#include "../../MyLinux.h"
#include <errno.h>		/* for definition of errno */
#include <stdarg.h>		/* ISO C variable aruments */

int main(int argc, char **argv)
{
	INITIALIZE_LOG(argv[0]);

	int fd[2], n;
	char c;
	pid_t childpid;

	pipe(fd);
	if((childpid=fork()) == 0)
	{
		sleep(3);
		if((n=read(fd[0], &c, 1))!=1)
			LOG_ERROR<< "child: read returned "<< n<< endl;
		printf("child read %c\n", c);
		write(fd[0], "c", 1);
		exit(0);
	}

	write(fd[1], "p", 1);
	if((n=read(fd[1], &c, 1))!=1)
		LOG_ERROR<< "parent: read returned "<< n<< endl;
	printf("parent read %c\n", c);
	exit(0);
	return 0;
}