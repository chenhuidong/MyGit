#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sfd = socket(AF_INET, SOCK_STREAM, 6);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(54321);
	inet_aton("127.0.0.1", &addr.sin_addr);

	bind(sfd, (struct sockaddr*)&addr, sizeof(addr));

	listen(sfd, 10);

	int maxfd = sfd;
	fd_set fset, fsetbak;
	FD_ZERO(&fset);
	FD_ZERO(&fsetbak);
	FD_SET(sfd, &fsetbak);

	while(1)
	{
		
		select(maxfd+1, &fset, 0, 0, 0);

	}

	return 0;
}