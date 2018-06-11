#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	int r;
	struct flock lk;
	fd = open("fork.cpp", O_RDWR);
	if(fd == -1) printf("%m\n"),exit(-1);
	lk.l_type = F_WRLCK;
	lk.l_whence = SEEK_SET;
	lk.l_start = 5;
	lk.l_len = 10;
	r = fcntl(fd, F_SETLK, &lk);
	if(r == 0) printf("lock success.\n");
	else	printf("lock failed.\n");
	while(1);
	return 0;
}