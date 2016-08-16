#include "MyStdAfx.h"

int
main(int argc, char**argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);

	int		n;
	int		fd[2];
	pid_t	pid;
	char	line[MYSIZE];

	if (pipe(fd) < 0)
		LOG_ERROR<< "pipe error"<< endl;
	if ((pid = fork()) < 0) {
		LOG_ERROR<< "fork error"<< endl;
	} else if (pid > 0) {		/* parent */
		close(fd[0]);
		write(fd[1], "hello world\n", 12);
	} else {				/* child */
		close(fd[1]);
		n = read(fd[0], line, MYSIZE);
		//write(STDOUT_FILENO, line, n);
		LOG_INFO<< line<< endl;
	}
	exit(0);
}