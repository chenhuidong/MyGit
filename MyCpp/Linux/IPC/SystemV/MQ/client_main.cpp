#include	"svmsg.h"

void
client(int readfd, int writefd)
{
	size_t	len;
	ssize_t	n;
	char	buff[MAXLINE];

		/* 4read pathname */
	Fgets(buff, MAXLINE, stdin);
	len = strlen(buff);		/* fgets() guarantees null byte at end */
	if (buff[len-1] == '\n')
		len--;				/* delete newline from fgets() */

		/* 4write pathname to IPC channel */
	Write(writefd, buff, len);

		/* 4read from IPC, write to standard output */
	while ( (n = Read(readfd, buff, MAXLINE)) > 0)
		Write(STDOUT_FILENO, buff, n);
}

int
main(int argc, char **argv)
{
	int		readid, writeid;

		/* 4assumes server has created the queues */
	writeid = Msgget(MQ_KEY1, 0);
	readid = Msgget(MQ_KEY2, 0);

	client(readid, writeid);

		/* 4now we can delete the queues */
	Msgctl(readid, IPC_RMID, NULL);
	Msgctl(writeid, IPC_RMID, NULL);

	exit(0);
}
