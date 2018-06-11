#include <stdio.h>
#include <signal.h>

int main()
{
	kill(3828, SIGINT);
	sleep(2);
	return 0;
}