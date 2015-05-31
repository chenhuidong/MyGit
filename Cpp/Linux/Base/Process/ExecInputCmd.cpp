#include "../../../stdafx.h"
#include "../../../MySys.h"

int main()
{
	char buf[BUFFSIZE];
	pid_t pid;
	int status;

	cout<< "%% " <<endl;
	while(fgets(buf, BUFFSIZE, stdin) != NULL)
	{
		if(buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = 0;

		if((pid = fork()) < 0)
		{
			cout<< "fork error." <<endl;
		}
	}
	return 0;
}