#include <unistd.h>
#include <stdio.h>
int main(void)
{ 
	int counter; 
	alarm(5); 

	for(counter=0; 1; counter++) 
	{
		printf("counter=%d\n", counter); 
		sleep(1);
	}
	return 0;
}