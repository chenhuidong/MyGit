#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int fd;
	struct sockaddr_in ad;
	char buf[100];
	int r;

	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd == -1) printf("socket:%m\n"),exit(-1);

	ad.sin_family=AF_INET;
	ad.sin_port= htons(54328);
	ad.sin_addr.s_addr = inet_addr("127.0.0.1");

	//connect(fd, (struct sockaddr *)&ad, sizeof(ad));
	while(1)
	{
		r = read(0, buf, sizeof(buf)-1);
		if(r<=0) break;
		buf[r] = '\0';

		r= sendto(fd, buf, r, 0, (struct sockaddr*)&ad, sizeof(ad));
		//r = send(fd, buf, r, 0);

		bzero(buf,sizeof(buf));
		r = recv(fd, buf, sizeof(buf)-1, 0);
		buf[r] = 0;
		printf("receiver data:%s\n", buf);
		if(r == -1)
			break;


	}
	close(fd);
	return 0;
}