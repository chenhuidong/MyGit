#include "../../../MyLinux.h"

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int mqid;
	size_t len;
	long type;
	struct msgbuf *ptr;

	if(argc != 4)
		cout<< "usage: msgsnd <pathname> <#bytes> <type>"<<endl;

	len = atoi(argv[2]);
	type = atoi(argv[3]);

	mqid = msgget(ftok(argv[1], 0), MSG_W);
	ptr = (struct msgbuf *)calloc(sizeof(long)+len, sizeof(char));
	ptr->mtype = type;

	msgsnd(mqid, ptr, len, 0);
	return 0;
}