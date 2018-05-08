#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>

void * run(void *data)
{
	printf("i am thread.\n");
	//return (void*)"fdsf";
	pthread_exit((void*)"world");
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, 0, run, 0);
	//sleep(1);
	//sched_yield();
	char* re;
	pthread_join(tid, (void **)&re);
	printf("status: %s\n", re);

	return 0;
}