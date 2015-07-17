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
	char name[4];
	int age;
};
  
int main(void)  
{  
    int     shmid;  
    char    *shmptr;  
  
    if ( (shmid = shmget(0x44, SHM_SIZE, SHM_MODE | IPC_CREAT)) < 0)  
        perror("shmget");  
  
    if ( (shmptr = (char *)shmat(shmid, 0, 0)) == (void *) -1)  
        perror("shmat");  
      
    /* 往共享内存写数据 */  
    //sprintf(shmptr, "%s", "hello world.");  
    
    People people;
    strncpy(people.name, "aaa", 4);
    people.age = 12;
  
    exit(0);  
}  