#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sched.h>

int main()
{
	//int *a = (int *)malloc(4);
	//int *a = (int *)mmap(0, 4, PROT_READ|PROT_WRITE, MAP_ANONYMOUS | /*MAP_SHARED*/ MAP_PRIVATE, 0, 0);
	int *a = (int *)sbrk(4);
	*a = 40;

	if(fork())
	{
		printf("parent:%d\n", *a);
		sched_yield();
		*a = 90;
	}
	else
	{
		printf("child:%d\n", *a);
		sleep(3);
		printf("child:%d\n", *a);
	}
	return 0;
}