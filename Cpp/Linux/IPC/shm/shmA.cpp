#include    <sys/types.h>  
#include    <sys/ipc.h>  
#include    <sys/shm.h>  
#include    <stdio.h>  
#include    <error.h>  
#include "../../../stdafx.h"
  
#define SHM_SIZE    4096  
#define SHM_MODE    (SHM_R | SHM_W) /* user read/write */  

class People
{
public:
	char name[10];
	int age;
};
  
int main(void)  
{  
    int     shmid;  
    People  *shmptr;  
  
    if ( (shmid = shmget(0x44, SHM_SIZE, SHM_MODE | IPC_CREAT)) < 0)  
        perror("shmget");  
  
    if ( (shmptr = (People *)shmat(shmid, 0, 0)) == (void *) -1)  
        perror("shmat");  
      
    /* 往共享内存写数据 */  
    //sprintf(shmptr, "%s", "hello world.");  
    
    //People people;
    strncpy(shmptr->name, "aaa", 4);
    shmptr->age = 13;
 	
 	shmptr++;

    strncpy(shmptr->name, "bbbb", 4);
    shmptr->age = 12;
    exit(0);  
}  