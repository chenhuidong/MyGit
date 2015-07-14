#include "../../../MyLinux.h"

void server(int readfd, int writefd)
{
	int fd;
	size_t n;
	char buf[BUFFSIZE];

	if((n=read(stdin, buf, BUFFSIZE)) == 0)
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

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int readid, writeid;
	readid = msgget(MQ_KEY1, SVMSG_MODE | IPC_CREAT);
	writeid = msgget(MQ_KEY2, SVMSG_MODE | IPC_CREAT);

	server(readid, writeid);
	return 0;
}