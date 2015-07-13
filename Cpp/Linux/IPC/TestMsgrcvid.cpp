#include "../../MyLinux.h"
#define MSGMAX (8192+sizeof(long))

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int mqid;
	ssize_t n;
	struct msgbuf* buff;

	if(argc != 2)
		cout<< "usage: msgrcvid <mqid>"<< endl;

	mqid = atoi(argv[1]);
	buff = (msgbuf*)malloc(MSGMAX);

	n = msgrcv(mqid, buff, MSGMAX, 0, 0);
	printf("read %d bytes, type = %ldn", n, buff->mtype);
	return 0;
}