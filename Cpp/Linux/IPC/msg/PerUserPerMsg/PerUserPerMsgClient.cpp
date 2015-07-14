#define __MY_ERROR_
#include "../../../../MyLinux.h"

void
client(int readid, int writeid)
{
	size_t	len;
	ssize_t	n;
	char	*ptr;
	struct mymesg	mesg;

		/* 4start buffer with msqid and a blank */
	snprintf(mesg.mesg_data, MAXMESGDATA, "%d ", readid);
	len = strlen(mesg.mesg_data);
	ptr = mesg.mesg_data + len;

		/* 4read pathname */
	fgets(ptr, MAXMESGDATA - len, stdin);
	len = strlen(mesg.mesg_data);
	if (mesg.mesg_data[len-1] == '\n')
		len--;				/* delete newline from fgets() */
	mesg.mesg_len = len;
	mesg.mesg_type = 1;

		/* 4write msqid and pathname to server's well-known queue */
	Mesg_send(writeid, &mesg);

		/* 4read from our queue, write to standard output */
	while ( (n = Mesg_recv(readid, &mesg)) > 0)
		Write(STDOUT_FILENO, mesg.mesg_data, n);
}


int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int readid, writeid;
	writeid = msgget(MQ_KEY1, 0);
	readid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);

	client(readid, writeid);

	msgctl(readid, IPC_RMID, NULL);
	return 0;
}