/*
  shmget(  )  创建一个新的共享内存区段
              取得一个共享内存区段的描述符
  shmctl(  )  取得一个共享内存区段的信息
              为一个共享内存区段设置特定的信息
              移除一个共享内存区段
  shmat(  )   挂接一个共享内存区段
  shmdt(  )   于一个共享内存区段的分离
 */
//创建一个共享内存区段，并显示其相关信息，然后删除该内存共享区
#include <stdio.h>
#include <unistd.h>  //getpagesize(  )
#include <sys/ipc.h>
#include <sys/shm.h>
#define MY_SHM_ID 67483

int main(  )
{
        //获得系统中页面的大小
    printf( "page size=%d/n",getpagesize(  ) );
        //创建一个共享内存区段
    int shmid,ret;
    shmid=shmget( MY_SHM_ID,4096,0666|IPC_CREAT );
        //创建了一个4KB大小共享内存区段。指定的大小必须是当前系统架构
        //中页面大小的整数倍
    if( shmid>0 )
        printf( "Create a shared memory segment %d/n",shmid );
        //获得一个内存区段的信息
    struct shmid_ds shmds;
        //shmid=shmget( MY_SHM_ID,0,0 );//示例怎样获得一个共享内存的标识符
    ret=shmctl( shmid,IPC_STAT,&shmds );
    if( ret==0 )
    {
        printf( "Size of memory segment is %d/n",shmds.shm_segsz );
        printf( "Numbre of attaches %d/n",( int )shmds.shm_nattch );
    }
    else
    {
        printf( "shmctl(  ) call failed/n" );
    }
        //删除该共享内存区
    ret=shmctl( shmid,IPC_RMID,0 );
    if( ret==0 )
        printf( "Shared memory removed /n" );
    else
        printf( "Shared memory remove failed /n" );
    return 0;
}