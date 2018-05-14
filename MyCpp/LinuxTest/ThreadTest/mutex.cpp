#include <stdio.h>
#include <pthread.h>

pthread_mutex_t m;

int a = 0, b=0;

void display()
{
//
}

void * r1(void *data)
{
	while(1)
	{
	pthread_mutex_lock(&m);
	a++;
	b++;
	if(a!=b)
	{
		printf("%d != %d", a, b);
		a=b=0;
	}
	pthread_mutex_unlock(&m);
	}
}


void * r2(void *data)
{
	while(1)
	{
	pthread_mutex_lock(&m);
	a++;
	b++;
	if(a!=b)
	{
		printf("%d != %d", a, b);
		a=b=0;
	}
	pthread_mutex_unlock(&m);
	}
}


int main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&m, 0);

	pthread_create(&t1, 0, r1, 0);
	pthread_create(&t2, 0, r2, 0);
	pthread_join(t1,(void**)0);
	pthread_join(t2,(void**)0);
	pthread_mutex_destroy(&m);
	return 0;
}