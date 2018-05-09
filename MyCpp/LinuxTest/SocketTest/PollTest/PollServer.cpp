#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <list>
#include <signal.h>
#include <poll.h>
using namespace std;

#define OPEN_MAX 1024

int g_stop = 0;

void handler(int num) {
	g_stop = 1;
	printf("recv stop signal.\n");
}

int main()
{
	signal(SIGINT,  handler);
	signal(SIGQUIT, handler);
	signal(SIGTERM, handler);

	int r = 0;
	int size = 0;
	int sfd = socket(AF_INET, SOCK_STREAM, 6);
	printf("socket success.\n");
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(54321);
	inet_aton("127.0.0.1", &addr.sin_addr);
	bind(sfd, (struct sockaddr*)&addr, sizeof(addr));
	printf("bind success.\n");

	listen(sfd, 10);
	printf("listen success.\n");

	struct pollfd fds[OPEN_MAX];
	char buf[10];

	for(int i=0; i<OPEN_MAX; ++i)
	{
		fds[i].fd = -1;
	}

	fds[0].fd = sfd;
	fds[0].events = POLLIN;
	
	while(1)
	{
		if(g_stop) break;
		//printf("flist %d.\n", flist.size());
		poll(fds, OPEN_MAX, 0);
		for(int i=0; i<OPEN_MAX; ++i)
		{
			if(g_stop) break;
			if(fds[i].revents & POLLIN)
			{
				if(0==i)
				{
					int cfd = accept(sfd, 0, 0);
					for(int i=0; i<OPEN_MAX; ++i)
					{
						if(fds[i].fd == -1)
						{
							fds[i].fd = cfd;
							fds[i].events = POLLIN;
						}

					}
					printf("someone connect %d.\n", cfd);
				}
				else
				{
					size = read(fds[i].fd, buf, 9);
					if(size > 0)
					{
						buf[size] = '\0';
						printf("%d recv msg: %s.\n", fds[i].fd, buf);
					}
					else if(size == 0)
					{
						close(fds[i].fd);
						fds[i].fd = -1;
						break;
					}
					else
					{
						close(fds[i].fd);
						fds[i].fd = -1;
						printf("read err.\n");
						break;
					}
				}
			}
		}
	}

	for(int i=0; i<OPEN_MAX; ++i)
	{
		if(fds[i].fd != -1)
			close(fds[i].fd);
	}

	return 0;
}