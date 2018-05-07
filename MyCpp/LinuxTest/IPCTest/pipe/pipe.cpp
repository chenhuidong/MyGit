#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

int main()
{
	int fd[2];
	int ret = pipe(fd);  
    if (ret == -1)  
    {  
        printf("pipe error\n"); 
        return 1;  
    } 

	int pid = fork();
	if(pid < 0)
	{
		printf("fork err.\n");
	} 
	else if(pid == 0)
	{
		printf("child.\n");
		close(fd[0]);
		while(1)
		{
			write(fd[1], "hello", strlen("hello"));
			sleep(1);
		}
	}
	else
	{
		printf("parent.\n");
		close(fd[1]);
		char buf[10] = {0};
		while(1)
		{
			int size = read(fd[0], buf, sizeof(buf));
			buf[size] = '\0';
			printf("%s\n", buf);
			sleep(2);
		}
	}


	return 0;
}