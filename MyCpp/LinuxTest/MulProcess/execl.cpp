#include <stdio.h>
#include <unistd.h>

int main()
{
	int r = execl("/bin/ls","ls", "-l", NULL);
	//int r = execlp("ls","ls", "-l", NULL);
	printf("result: %d", r);
	return 0;
}