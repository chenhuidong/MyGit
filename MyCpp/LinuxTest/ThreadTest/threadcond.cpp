#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
pthread_t todd, teven;
pthread_cond_t cond;
pthread_mutex_t m;
void handle(void *d)
{
	printf("after exit.\n");
}

void* runodd(void *d)
{
	int s;
	while(1)
	{
		printf("1.\n");
		pthread_cond_wait(&cond, &m);
		printf("recv %d\n", s);
	}
}

void* runeven(void *d)
{
	while(1)
	{
		printf("2.\n");
		sleep(1);
		pthread_cond_signal(&cond);
	}
}

int main()
{
	pthread_mutex_init(&m, 0);
	pthread_cond_init(&cond, 0);
	pthread_create(&todd,0, runodd, 0);
	pthread_create(&teven,0, runeven, 0);

	pthread_join(todd, (void **)0);
	pthread_join(teven, (void **)0);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&m);
	return 0;
}