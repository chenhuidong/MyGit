#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
sem_t sem;
void *run(void* d)
{
	while(1)
	{
		sem_wait(&sem);
		printf("no\n");
	}
}

int main()
{
	pthread_t tid;
	sem_init(&sem, 0, 5);
	pthread_create(&tid, 0, run, 0);
	while(1)
	{
		sleep(1);
		sem_post(&sem);
	}
	return 0;
}