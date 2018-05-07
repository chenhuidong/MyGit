#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int serverfd;
	int cfd;
	struct sockaddr_in sadr,  cadr;
	int r;
	char buf[102];
	socklen_t len;

	serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if(serverfd == -1) printf("1:%m"), exit(-1);

	printf("socket success.\n");

	sadr.sin_family = AF_INET;
	sadr.sin_port = htons(54321);
	inet_aton("127.0.0.1", &sadr.sin_addr);

	r = bind(serverfd, (struct sockaddr*)&sadr, sizeof(sadr));
	if(r == -1) printf("2:%m"), exit(-1);

	printf("bind success.\n");

	r = listen(serverfd, 10);
	if(r == -1) printf("3:%m"), exit(-1);
	printf("listen success.\n");

	while(1)
	{
		len = sizeof(cadr);
		cfd = accept(serverfd, (struct sockaddr*)&cadr, &len);
		printf("someone connect:%d, IP:%s:%u\n",
			cfd, inet_ntoa(cadr.sin_addr),
			ntohs(cadr.sin_port));

		while(1)
		{
		//deal data
		r = recv(cfd, buf, 100, MSG_WAITALL);
		if(r>0)
		{
			buf[r] = 0;
			printf("%s\n", buf);
		}

		if(r == 0)
		{
			printf("disconnect.\n");
			break;
		}
		if(r==-1)
		{
			printf("net err.\n");
			break;
		}
		}
		close(cfd);
		close(serverfd);
		break;
	}

	return 0;
}