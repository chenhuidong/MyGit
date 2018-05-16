#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
pthread_t todd, teven;
sigset_t sigs;
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
		sigwait(&sigs, &s);
		printf("recv %d\n", s);
	}
}

void* runeven(void *d)
{
	while(1)
	{
		printf("2.\n");
		sleep(2);
		pthread_kill(todd, SIGUSR1);
	}
}

int main()
{
	sigemptyset(&sigs);
	sigaddset(&sigs, SIGUSR1);
	pthread_create(&todd,0, runodd, 0);
	pthread_create(&teven,0, runeven, 0);

	pthread_join(todd, (void **)0);
	pthread_join(teven, (void **)0);

	return 0;
}