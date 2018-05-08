#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <list>
#include <signal.h>
using namespace std;

int g_stop = 0;

void handler(int num) {
	g_stop = 1;
	printf("recv stop signal.\n");
}

int main()
{
	signal(SIGINT, handler);
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

	int maxfd = sfd;
	fd_set fset;
	FD_ZERO(&fset);
	list<int> flist;
	flist.push_back(sfd);
	char buf[10];

	while(!g_stop)
	{
		FD_ZERO(&fset);
		maxfd = sfd;
		printf("flist %d.\n", flist.size());
		for(list<int>::iterator it=flist.begin(); it!=flist.end(); ++it)
		{
			FD_SET(*it, &fset);
			maxfd=maxfd>(*it)?maxfd:(*it);
		}

		select(maxfd+1, &fset, 0, 0, 0);

		for(list<int>::iterator it=flist.begin(); it!=flist.end(); ++it)
		{
			if(FD_ISSET(*it, &fset))
			{
				if(*it == sfd)
				{
					int cfd = accept(sfd, 0, 0);
					flist.push_back(cfd);
					maxfd=maxfd>cfd?maxfd:cfd;
					printf("someone connect %d,%d.\n", cfd, maxfd);
				}
				else
				{
					size = read(*it, buf, 9);
					if(size > 0)
					{
						buf[size] = '\0';
						printf("%d recv msg: %s.\n", *it, buf);
					}
					else if(size == 0)
					{
						close(*it);
						flist.erase(it);
						break;
					}
					else
					{
						close(*it);
						flist.erase(it);
						printf("read err.\n");
						break;
					}
				}
			}
		}
	}

	for(list<int>::iterator it=flist.begin(); it!=flist.end(); ++it)
	{
		close(*it);
	}

	return 0;
}