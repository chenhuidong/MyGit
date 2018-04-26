#include <stdio.h>
#include <netdb.h>

int main()
{
	struct hostent *ent;
	ent = gethostbyname("www.baidu.com");
	//printf("%s\n", ent->aliases[0]);
	printf("ip:%hhu.%hhu.%hhu.%hhu\n", 
		ent->h_addr_list[0][0], 
		ent->h_addr_list[0][1], 
		ent->h_addr_list[0][1], 
		ent->h_addr_list[0][3]);
	return 0;
}