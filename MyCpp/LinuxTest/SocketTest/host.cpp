#include <stdio.h>
#include <netdb.h>

int main()
{
	struct hostent *ent;
	//打开主机配置数据库文件
	sethostent(1);
	while(1)
	{
		ent = gethostent();
		if(!ent) break;

		printf("hostname:%s\n", ent->h_name);
		printf("ip:%hhd.%hhd.%hhd.%hhd\n", ent->h_addr[0], ent->h_addr[1]
			, ent->h_addr[1], ent->h_addr[3]);
	}

	endhostent();
	return 0;
}