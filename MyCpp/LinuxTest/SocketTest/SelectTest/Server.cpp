#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sfd;
	int fdall[100];
	int count;
	int r;
	struct sockaddr_in dr;
	fd_set fds; 
	int maxfd;

	sfd = socket(AF_INET, SOCK_STREAM, 6);
	printf("socket success.\n");

	dr.sin_family = AF_INET;
	dr.sin_port = htons(54321);
	inet_aton("127.0.0.1", &dr.sin_addr);

	r = bind(sfd, (struct sockaddr*)&dr, sizof(dr));

	printf("bind success.\n");

	r = listen(sfd, 10);
	printf("listen success.\n");

	count = 0;
	maxfd = 0;
	FD_ZERO(&fds);

	for(int i =0; i<100; i++)
	{
		fdall[i] = -1;
	}

	while(1)
	{
		FD_ZERO(&fds);
		maxfd = 0;
		FD_SET(sfd, &fds);
		maxfd = maxfd>=sfd?maxfd:sfd;
		for(int i=0;i<count;i++)
		{
			if(fdall[i]!=-1)
			{
				FD_SET(fdall[i],&fds);
				maxfd = maxfd> =fdall[i]?maxfd:fdall[i];
			}
		}

		r = select(maxfd+1, &fds, 0, 0, 0);

		if(FD_ISSET(sfd, &fds))
		{
			fdall[count] = accept(sfd, 0, 0);
			count++;
			printf("someone connect.\n");
		}
	}


	return 0;
}