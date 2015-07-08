#include "../../MyLinux.h"
#include <errno.h>		/* for definition of errno */
#include <stdarg.h>		/* ISO C variable aruments */

void  client(int, int), server(int, int);

int main()
{
	int pipe1[2], pipe2[2];
	pid_t childpid;

	pipe(pipe1);
	pipe(pipe2);

	if((childpid = fork()) == 0)
	{
		close(pipe1[1]);
		close(pipe2[0]);
		server(pipe1[0], pipe2[1]);
		exit(0);
	}

	close(pipe1[0]);
	close(pipe2[1]);

	client(pipe2[0], pipe1[1]);

	waitpid(childpid, NULL, 0);
	return 0;
}

void client(int readfd, int writefd)
{
	size_t len;
	size_t n;
	char buf[BUFFSIZE];

	fgets(buf, BUFFSIZE, stdin);
	len=strlen(buf);

	if(buf[len-1] == '\n')
		len--;

	write(writefd, buf, len);
	while((n = read(readfd, buf, BUFFSIZE))>0)
		write(STDOUT_FILENO, buf, n);
}

void server(int readfd, int writefd)
{
	int fd;
	size_t n;
	char buf[BUFFSIZE];

	if((n=read(readfd, buf, BUFFSIZE)) == 0)
		LOG_ERROR << "end-of-file while reading pathname" <<endl;

	buf[n] = '\0';

	if((fd = open(buf, O_RDONLY))<0)
	{
		snprintf(buf+n, sizeof(buf)-n, "can not open, %sn", stderr(errno));
		n = strlen(buf);
		write(writefd, buf, n);
	}
	else
	{
		while((n=read(fd, buf, BUFFSIZE))>0)
			write(writefd, buf, n);
		close(fd);
	}
}