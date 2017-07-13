#include	"svmsg.h"

void
client(int readfd, int writefd)
{
	size_t	len;
	ssize_t	n;
	char	buff[MAXLINE];

		/* 4read pathname */
	fgets(buff, MAXLINE, stdin);
	len = strlen(buff);		/* fgets() guarantees null byte at end */
	if (buff[len-1] == '\n')
		len--;				/* delete newline from fgets() */

		/* 4write pathname to IPC channel */
	write(writefd, buff, len);

		/* 4read from IPC, write to standard output */
	while ( (n = read(readfd, buff, MAXLINE)) > 0)
		write(STDOUT_FILENO, buff, n);
}

int
main(int argc, char **argv)
{
	int		readid, writeid;

		/* 4assumes server has created the queues */
	writeid = msgget(MQ_KEY1, 0);
	readid = msgget(MQ_KEY2, 0);

	client(readid, writeid);

		/* 4now we can delete the queues */
	msgctl(readid, IPC_RMID, NULL);
	msgctl(writeid, IPC_RMID, NULL);

	exit(0);
}
