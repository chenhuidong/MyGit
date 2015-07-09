#include "../../MyLinux.h"
#include <errno.h>		/* for definition of errno */
#include <stdarg.h>		/* ISO C variable aruments */

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"

void  client(int, int), server(int, int);

int main(int argc, char** argv)
{
	int readfd, writefd;
	pid_t childpid;

	if((mkfifo(FIFO1, FILE_MODE)<0) && (errno != EEXIST))
		LOG_ERROR<< "can not create "<< FIFO1<<endl;

	if((mkfifo(FIFO2, FILE_MODE)<0) && (errno != EEXIST))
	{
		unlink(FIFO1);
		LOG_ERROR<< "can not create "<< FIFO2<<endl;
	}

	if((childpid = fork())==0)
	{
		readfd = open(FIFO1, O_RDONLY, 0);
		writefd = open(FIFO2, O_RDONLY, 0);

		server(readfd, writefd);
		exit(0);
	}

	writefd = open(FIFO1, O_RDONLY, 0);
	readfd = open(FIFO2, O_RDONLY, 0);
	client(readfd, writefd);

	unlink(FIFO1);
	unlink(FIFO2);
	return 0;
}

//parent
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

//child
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
		snprintf(buf+n, sizeof(buf)-n, "can not open, %sn", strerror(errno));
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