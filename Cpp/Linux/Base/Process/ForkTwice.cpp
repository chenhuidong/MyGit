#include "../../../stdafx.h"
#include "../../../MyError.h"
#include "../../../MySys.h"

int main()
{
	pid_t pid;
	if((pid=fork())<0)
	{
		err_sys("fork error");
	}
	else if(pid==0)
	{
		if((pid=fork())<0)
			err_sys("fork error");
		else if(pid>0)
			exit(0);

		sleep(2);
		printf("second child, parent pid = %dn", getppid());
		exit(0);
	}

	if(waitpid(pid, NULL, 0) != pid)
		err_sys("waitpid error");
	return 0;
}