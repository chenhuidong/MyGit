#include "../../../stdafx.h"
#include "../../../MySys.h"
#include "../../../apue.h"

int main()
{
	char buf[BUFFSIZE];
	pid_t pid;
	int status;

	cout<< "%% ";
	while(fgets(buf, BUFFSIZE, stdin) != NULL)
	{
		if(buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1] = 0;

		if((pid = fork()) < 0)
		{
			err_sys("fork error." );
		}
		else if(pid == 0)
		{
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		if((pid = waitpid(pid, &status, 0)) <0)
			err_sys("waitpid error." );
		printf("%% ");
	}
	return 0;
}