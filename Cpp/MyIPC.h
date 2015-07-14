#ifndef __MY_IPC_H_
#define __MY_IPC_H_

#include "stdafx.h"
#include "MyError.h"

#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define FILE_MODE 0644
#define DIR_MODE 0755
#define SVMSG_MODE 0660
#define SVSEM_MODE 0660
#define SVSHM_MODE 0660

#define MSG_W 0200
#define MSG_R 0400

#define MQ_KEY1 1234L
#define MQ_KEY2 2345L


//msg
/* Our own "messages" to use with pipes, FIFOs, and message queues. */

	/* 4want sizeof(struct mymesg) <= PIPE_BUF */
#define	MAXMESGDATA	(PIPE_BUF - 2*sizeof(long))

	/* 4length of mesg_len and mesg_type */
#define	MESGHDRSIZE	(sizeof(struct mymesg) - MAXMESGDATA)

struct mymesg {
  long	mesg_len;	/* #bytes in mesg_data, can be 0 */
  long	mesg_type;	/* message type, must be > 0 */
  char	mesg_data[MAXMESGDATA];
};

ssize_t	 mesg_send(int, struct mymesg *);
void	 Mesg_send(int, struct mymesg *);
ssize_t	 mesg_recv(int, struct mymesg *);
ssize_t	 Mesg_recv(int, struct mymesg *);

ssize_t
mesg_recv(int fd, struct mymesg *mptr)
{
	size_t	len;
	ssize_t	n;

		/* 4read message header first, to get len of data that follows */
	if ( (n = read(fd, mptr, MESGHDRSIZE)) == 0)
		return(0);		/* end of file */
	else if (n != MESGHDRSIZE)
		err_quit("message header: expected %d, got %d", MESGHDRSIZE, n);

	if ( (len = mptr->mesg_len) > 0)
		if ( (n = read(fd, mptr->mesg_data, len)) != len)
			err_quit("message data: expected %d, got %d", len, n);
	return(len);
}
/* end mesg_recv */

ssize_t
Mesg_recv(int fd, struct mymesg *mptr)
{
	return(mesg_recv(fd, mptr));
}

ssize_t
mesg_send(int fd, struct mymesg *mptr)
{
	return(write(fd, mptr, MESGHDRSIZE + mptr->mesg_len));
}
/* end mesg_send */

void
Mesg_send(int fd, struct mymesg *mptr)
{
	ssize_t	n;

	if ( (n = mesg_send(fd, mptr)) != mptr->mesg_len)
		err_quit("mesg_send error");
}


#endif
