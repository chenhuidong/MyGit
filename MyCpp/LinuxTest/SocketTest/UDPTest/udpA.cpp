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
	struct sockaddr_in ad_snd;
	socklen_t len;
	int r;

	fd = socket(AF_INET, SOCK_DGRAM, 17); //getprotobyname("udp")
	if(fd == -1) printf("socket:%m\n"),exit(-1);

	printf("socket success.\n");

	ad.sin_family = AF_INET;
	ad.sin_port = htons(54328);
	inet_aton("127.0.0.1", &ad.sin_addr);

	r= bind(fd, (struct sockaddr*)&ad, sizeof(ad));

	if(r == -1) printf("bind err:%m\n"),exit(-1);

	printf("bind success.\n");

	while(1)
	{
		len = sizeof(ad_snd);
		r = recvfrom(fd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&ad_snd, &len);

		if(r>0)
		{
			buf[r] = 0;
			printf("sender ip:%s, port:%hu, data:%s\n",
				inet_ntoa(ad_snd.sin_addr),
				ntohs(ad_snd.sin_port), 
				buf);
			sendto(fd,buf, r, 0, (struct sockaddr*)&ad_snd, sizeof(ad_snd));
		}
		if(r == 0)
		{
			printf("sender close.\n");
			close(fd);
			break;
		}
		if(r==-1)
		{
			printf("net err.\n");
			close(fd);
			break;
		}
	}
	close(fd);
	return 0;
}