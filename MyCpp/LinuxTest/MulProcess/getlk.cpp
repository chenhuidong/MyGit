#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	int r;
	struct flock lk={0};
	fd = open("fork.cpp", O_RDWR);
	if(fd == -1) printf("%m\n"),exit(-1);

	r = fcntl(fd, F_GETLK, &lk);
	if(r == 0) printf("get lock success.\n");
	if(lk.l_type == F_WRLCK)
	{
		printf("write lock.\n");
	}
	printf("start:%d,len:%d,pid:%d\n",lk.l_start, lk.l_len,lk.l_pid);
	return 0;
}