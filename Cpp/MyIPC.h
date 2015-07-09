#ifndef __MY_IPC_H_
#define __MY_IPC_H_

#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define DIR_MODE (FILE_MODE|S_IXUSR|S_IXGRP|S_IXOTH)
#define SVMSG_MODE (MSG_R|MSG_W|MSG_R>>3|MSG_R>>6)
#define SVSEM_MODE (SEM_R|SEM_A|SEM_R>>3|SEM_R>>6)
#define SVSHM_MODE (SHM_R|SHM_W|SHM_R>>3|SHM_R>>6)

#endif
