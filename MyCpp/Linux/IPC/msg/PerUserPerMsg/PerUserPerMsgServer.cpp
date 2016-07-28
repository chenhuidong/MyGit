#define __MY_ERROR_
#include "../../../../MyLinux.h"

void
sig_chld(int signo)
{
	pid_t	pid;
	int		stat;

	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
		;
	return;
}


void
server(int readid, int writeid)
{
	FILE	*fp;
	char	*ptr;
	ssize_t	n;
	struct mymesg	mesg;
	void	sig_chld(int);

	signal(SIGCHLD, sig_chld);

	for ( ; ; ) {
			/* 4read pathname from our well-known queue */
		mesg.mesg_type = 1;
		if ( (n = Mesg_recv(readid, &mesg)) == 0) {
			err_msg("pathname missing");
			continue;
		}
		mesg.mesg_data[n] = '\0';	/* null terminate pathname */

		if ( (ptr = strchr(mesg.mesg_data, ' ')) == NULL) {
			err_msg("bogus request: %s", mesg.mesg_data);
			continue;
		}
		*ptr++ = 0;			/* null terminate msgid, ptr = pathname */
		writeid = atoi(mesg.mesg_data);

		if (fork() == 0) {		/* child */
			if ( (fp = fopen(ptr, "r")) == NULL) {
					/* 4error: must tell client */
				snprintf(mesg.mesg_data + n, sizeof(mesg.mesg_data) - n,
						 ": can't open, %s\n", strerror(errno));
				mesg.mesg_len = strlen(ptr);
				memmove(mesg.mesg_data, ptr, mesg.mesg_len);
				Mesg_send(writeid, &mesg);
		
			} else {
					/* 4fopen succeeded: copy file to client's queue */
				while (fgets(mesg.mesg_data, MAXMESGDATA, fp) != NULL) {
					mesg.mesg_len = strlen(mesg.mesg_data);
					Mesg_send(writeid, &mesg);
				}
				fclose(fp);
			}
		
				/* 4send a 0-length message to signify the end */
			mesg.mesg_len = 0;
			Mesg_send(writeid, &mesg);
			exit(0);		/* child terminates */
		}
		/* parent just loops around */
	}
}

int main(int argc, char** argv)
{
	INITIALIZE_LOG(argv[0]);

	int msqid;
	msqid = msgget(MQ_KEY1, SVMSG_MODE | IPC_CREAT);

	server(msqid, msqid);
	return 0;
}