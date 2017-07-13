#include <iostream>  
#include <sys/ipc.h>  
#include <sys/msg.h>  
#include <cstring>  
using namespace std;  
  
struct msgbuff  
{  
    long mtype;  
    char mtext[100];  
};  

int main(int argc, char **argv)
{
	int msqid;
	struct msqid_ds info;
	struct msgbuf buf;

	msqid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);
	bug.mtype = 1;
	bug.mtext[0] = 1;
	msgsend(msqid, &buf, 1, 0);
	msgctl(msqid, IPC_STAT, &info);
	printf("read-write:%03o, cbytes = %lu, qnum = %lu, qbytes = %lu\n",
		info.msg_perm.mode & 0777, (ulong_t)info.msg_cbytes,
		(ulong_t)info.msg_qnum, (ulong_t)info.msg_qbytes);
	system("ipcs -q");
	msgctl(msqid, IPC_RMID, NULL);
	return 0;
}