#include	<sys/types.h>	/* basic system data types */
#include	<sys/time.h>	/* timeval{} for select() */
#include	<time.h>		/* timespec{} for pselect() */
#include	<errno.h>
#include	<fcntl.h>		/* for nonblocking */
#include	<limits.h>		/* PIPE_BUF */
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>	/* for S_xxx file mode constants */
#include	<unistd.h>
#include	<sys/wait.h>
#include <sys/ipc.h>  
#include <sys/msg.h>  
using namespace std;  
  
struct msgbuff  
{  
    long mtype;  
    char mtext[100];  
};  

#define SVMSG_MODE 0777
#define ulong_t ulong

int main(int argc, char **argv)
{
	int msqid;
	struct msqid_ds info;
	struct msgbuf buf;

	msqid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);
	buf.mtype = 1;
	buf.mtext[0] = 1;
	msgsnd(msqid, &buf, 1, 0);
	msgctl(msqid, IPC_STAT, &info);
	printf("read-write:%03o, cbytes = %lu, qnum = %lu, qbytes = %lu\n",
		info.msg_perm.mode & 0777, (ulong_t)info.msg_cbytes,
		(ulong_t)info.msg_qnum, (ulong_t)info.msg_qbytes);
	system("ipcs -q");
	msgctl(msqid, IPC_RMID, NULL);
	return 0;
}