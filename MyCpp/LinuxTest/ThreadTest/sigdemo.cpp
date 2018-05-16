#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
pthread_t todd, teven;
sigset_t sigs;

void handle(int s)
{
}

void* runodd(void *d)
{
	int s;
	for(int i=1;;i+=2)
	{
		sigwait(&sigs, &s);
		printf("%d.\n", i);
		
		//sched_yield();
		//pthread_kill(teven, 34);
	}
}

void* runeven(void *d)
{
	int s;
	for(int i=0;;i+=2)
	{
		printf("%d.\n", i);
		sleep(1);
		//sched_yield();
		pthread_kill(todd, 34);
		//sigwait(&sigs, &s);
	}
}

int main()
{
	signal(SIGUSR1, handle);
	sigemptyset(&sigs);
	sigaddset(&sigs,34);
	pthread_create(&todd,0, runodd, 0);
	pthread_create(&teven,0, runeven, 0);
	pthread_join(todd, (void **)0);
	pthread_join(teven, (void **)0);
	return 0;
}