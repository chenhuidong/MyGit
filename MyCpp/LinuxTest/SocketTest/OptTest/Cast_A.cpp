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
	struct sockaddr_in dr;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt));

	dr.sin_family = AF_INET;
	dr.sin_port = htons(54321);
	inet_aton("", &dr.sin_addr);

	sendto(fd, "Hello", 5, 0, (struct sockaddr *)&dr, sizof(dr));

	return 0;
}