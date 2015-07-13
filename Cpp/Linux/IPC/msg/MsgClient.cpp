#include "../../../MyLinux.h"

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

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int readid, writeid;
	writeid = msgget(MQ_KEY1, 0);
	readid = msgget(MQ_KEY2, 0);

	client(readid, writeid);

	msgctl(readid, IPC_RMID, NULL);
	msgctl(writeid, IPC_RMID, NULL);
	return 0;
}