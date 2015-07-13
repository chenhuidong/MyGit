#include "../../MyLinux.h"

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int msgid;
	struct msqid_ds info;
	struct msgbuf buf;

	msgid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);

	buf.mtype = 1;
	buf.mtext[0] = 1;
	msgsnd(msgid, &buf, 1, 0);
	msgctl(msgid, IPC_STAT, &info);

	printf("read-write: %03o, cbytes = %lu, qnum = %lu, qbytes = %lu\n", 
		info.msg_perm.mode & 0777, (uint64)info.msg_cbytes,
		(uint64)info.msg_qnum, (uint64)info.msg_qbytes);

	system("ipcs -q");
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}