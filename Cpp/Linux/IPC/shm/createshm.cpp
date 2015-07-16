/*共享内存允许两个或多个进程进程共享同一块内存(这块内存会映射到各个进程自己独立的地址空间)
  从而使得这些进程可以相互通信。
  在GNU/Linux中所有的进程都有唯一的虚拟地址空间，而共享内存应用编程接口API允许一个进程使
  用公共内存区段。但是对内存的共享访问其复杂度也相应增加。共享内存的优点是简易性。
  使用消息队列时，一个进程要向队列中写入消息，这要引起从用户地址空间向内核地址空间的一次复制，
  同样一个进程进行消息读取时也要进行一次复制。共享内存的优点是完全省去了这些操作。
  共享内存会映射到进程的虚拟地址空间，进程对其可以直接访问，避免了数据的复制过程。
  因此，共享内存是GNU/Linux现在可用的最快速的IPC机制。
  进程退出时会自动和已经挂接的共享内存区段分离，但是仍建议当进程不再使用共享区段时
  调用shmdt来卸载区段。
  注意，当一个进程分支出父进程和子进程时，父进程先前创建的所有共享内存区段都会被子进程继承。
  如果区段已经做了删除标记(在前面以IPC——RMID指令调用shmctl)，而当前挂接数已经变为0，
  这个区段就会被移除。
 */

//共享内存区段的挂载,脱离和使用
//理解共享内存区段就是一块大内存
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
#include "../../../stdafx.h"
#define SVSHM_MODE 0660
#define MY_SHM_ID 67483
int main(  )
{
    //共享内存区段的挂载和脱离
    int shmid,ret,oflag;
    void* mem;
    oflag = SVSHM_MODE | IPC_CREAT;
    shmid=shmget( MY_SHM_ID,0, oflag);
    printf( "chd %d\n", shmid);
    if( shmid>=0 )
    {
        mem=shmat( shmid,( const void* )0,0 );
        //shmat()返回进程地址空间中指向区段的指针
        if( (*(( int *)mem))!=-1 )
        {
            printf( "Shared memory was attached in our address space at %p\n",mem );
                        //向共享区段内存写入数据
            strcpy( ( char* )mem,"This is a test string.\n" );
            printf( "%s\n",(char*)mem );
                        //脱离共享内存区段
            ret=shmdt( mem );
            if( ret==0 )
                printf( "Successfully detached memory \n" );
            else
                printf( "Memory detached failed %d\n",errno );
        }
        else
            printf( "shmat(  ) failed\n" );

    }
    else
        printf( "shared memory segment not found\n" );
    return 0;
}
