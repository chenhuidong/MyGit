#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int fd;
	int type;
	int len;
	len = sizeof(type);

	fd = socket(AF_INET, SOCK_STREAM, 0);
	getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &type, (socklen_t *)&len);

	printf("rcvbuf:%u\n", type);
	/*
	getsockopt(fd, SOL_SOCKET, SO_TYPE, &type, (socklen_t *)&len);

	printf("%u:%u\n", SOCK_STREAM, type);

	if(type & SOCK_STREAM)
	{
		printf("stream.\n");
	}

	if(type & SOCK_DGRAM)
	{
		printf("dgram.\n");
	}
	*/

	return 0;
}