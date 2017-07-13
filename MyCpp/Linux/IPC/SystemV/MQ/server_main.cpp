#include	"svmsg.h"

void
server(int readfd, int writefd)
{
	int		fd;
	ssize_t	n;
	char	buff[MAXLINE+1];

		/* 4read pathname from IPC channel */
	if ( (n = read(readfd, buff, MAXLINE)) == 0)
		printf("end-of-file while reading pathname");
	buff[n] = '\0';		/* null terminate pathname */

	if ( (fd = open(buff, O_RDONLY)) < 0) {
			/* 4error: must tell client */
		snprintf(buff + n, sizeof(buff) - n, ": can't open, %s\n",
				 strerror(errno));
		n = strlen(buff);
		write(writefd, buff, n);

	} else {
			/* 4open succeeded: copy file to IPC channel */
		while ( (n = read(fd, buff, MAXLINE)) > 0)
			write(writefd, buff, n);
		close(fd);
	}
}

int
main(int argc, char **argv)
{
	int		readid, writeid;

	readid = msgget(MQ_KEY1, SVMSG_MODE | IPC_CREAT);
	writeid = msgget(MQ_KEY2, SVMSG_MODE | IPC_CREAT);

	server(readid, writeid);

	exit(0);
}
