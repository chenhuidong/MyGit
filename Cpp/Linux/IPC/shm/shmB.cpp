#include    <sys/types.h>  
#include    <sys/ipc.h>  
#include    <sys/shm.h>  
#include    <stdio.h>  
#include    <error.h>  
#include "../../../stdafx.h"
  
#define SHM_SIZE    4096  
#define SHM_MODE    (SHM_R | SHM_W | IPC_CREAT) /* user read/write */  
 
class People
{
public:
	char name[4];
	int age;
}; 

int main(void)  
{  
    int     shmid;  
    People    *shmptr;  
  
    if ( (shmid = shmget(0x44, SHM_SIZE, SHM_MODE | IPC_CREAT)) < 0)  
        perror("shmget");  
  
    if ( (shmptr = (People *)shmat(shmid, 0, 0)) == (void *) -1)  
        perror("shmat");  
  
    /* 从共享内存读数据 */  
    printf("%s\n", shmptr->name);  
  
    exit(0);  
}  