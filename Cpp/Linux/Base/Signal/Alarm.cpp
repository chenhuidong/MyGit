#include <unistd.h>
#include <stdio.h>
int main(void)
{ 
	int counter; 
	alarm(1); 

	for(counter=0; 1; counter++) 
	{
		printf("counter=%d\n", counter); 
		usleep(100);
	}
	return 0;
}