#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main()
{
	fd_set fds;
	int r;
	char buf[100];
	while(1)
	{
		FD_ZERO(&fds);
		FD_SET(0, &fds);
		r = select(1, &fds, 0, 0, 0);
		printf("some input.\n");
		r = read(0, buf, 99);
	}
	return 0;
}