#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int fd;
	struct sockaddr_in addr;
	int r;
	socklen_t len;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1) printf("1:%m"), exit(-1);

	printf("socket success.\n");

	addr.sin_family = AF_INET;
	addr.sin_port = htons(54321);
	inet_aton("127.0.0.1", &addr.sin_addr);

	r = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
	if(r == -1) printf("2:%m"), exit(-1);

	printf("connect success.\n");

	for(int i=0; i<20; i++)
	{
		send(fd,"hello",5,0);
	}

	return 0;
}