#include "../../../MyLinux.h"
#define MAXMSG (8192 + sizeof(long))

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int c, flag, mqid;
	long type;
	ssize_t n;
	struct msgbuf *buff;

	type = flag = 0;

	while((c = getopt(argc, argv,"nt:")) != -1)
	{
		switch(c)
		{
		case 'n':
			flag |= IPC_NOWAIT;
			break;
		case 'e':
			flag |= IPC_EXCL;
			break;
		}
	}

	if((optind != argc -1))
		cout<< "usage: msgrcv [-n] [-t type] <pathname>"<< endl;

	mqid = msgget(ftok(argv[optind], 0), MSG_R);
	buff = (struct msgbuf *)malloc(MAXMSG);

	n = msgrcv(mqid, buff, MAXMSG, type, flag);
	printf("read %d bytes, type = %ld\n", n, buff->mtype);
	return 0;
}