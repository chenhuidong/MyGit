#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int fd;
	int opt=1;
	char buf[100];
	int r ;
	struct sockaddr_in dr;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	dr.sin_family = AF_INET;
	dr.sin_port = htons(54321);
	inet_aton("", &dr.sin_addr);

	bind(fd, "Hello", 5, 0, (struct sockaddr *)&dr, sizof(dr));

	r = recv(fd, buf, 100, 0);
	buf[r] = '\0';
	printf("broad cast :%s n", buf);

	return 0;
}