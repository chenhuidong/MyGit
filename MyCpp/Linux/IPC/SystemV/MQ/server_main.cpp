#include	"svmsg.h"

void
server(int readfd, int writefd)
{
	int		fd;
	ssize_t	n;
	char	buff[MAXLINE+1];

		/* 4read pathname from IPC channel */
	if ( (n = Read(readfd, buff, MAXLINE)) == 0)
		err_quit("end-of-file while reading pathname");
	buff[n] = '\0';		/* null terminate pathname */

	if ( (fd = open(buff, O_RDONLY)) < 0) {
			/* 4error: must tell client */
		snprintf(buff + n, sizeof(buff) - n, ": can't open, %s\n",
				 strerror(errno));
		n = strlen(buff);
		Write(writefd, buff, n);

	} else {
			/* 4open succeeded: copy file to IPC channel */
		while ( (n = Read(fd, buff, MAXLINE)) > 0)
			Write(writefd, buff, n);
		Close(fd);
	}
}

int
main(int argc, char **argv)
{
	int		readid, writeid;

	readid = Msgget(MQ_KEY1, SVMSG_MODE | IPC_CREAT);
	writeid = Msgget(MQ_KEY2, SVMSG_MODE | IPC_CREAT);

	server(readid, writeid);

	exit(0);
}
