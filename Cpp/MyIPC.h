#ifndef __MY_IPC_H_
#define __MY_IPC_H_

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

#endif
