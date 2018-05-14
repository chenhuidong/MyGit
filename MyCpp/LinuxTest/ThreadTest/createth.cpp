#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
/*void call()
{
	pthread_exit("Kill");
	return;
}
*/

void * run(void *data)
{
	printf("i am thread. %s\n", (char *)data);
	//return (void*)"fdsf";
	pthread_exit((void*)"world");
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, 0, run, (void *)"jack");
	//sleep(1);
	//sched_yield();
	char* re;
	pthread_join(tid, (void **)&re);
	printf("status: %s\n", re);

	return 0;
}