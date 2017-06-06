#include "stdafx.h"
#include "Enum.h"

using namespace mypoker;

static void sig_handler(int)
{
	pid_t t_iWpid;
	int   t_iStat; 
	t_iWpid = waitpid(-1, &t_iStat, WNOHANG);
	if(t_iWpid == 0)
	{
		printf("The child process has not exited \n");  
		sleep(1);  
	}
	else if(t_iWpid > 0)
	{
		printf("child %d terminated\n", t_iWpid);
	}
}

int main(int argc, char** argv)
{
	if(signal(SIGCHLD, sig_handler) == SIG_ERR)  
    {  
        printf("signal error : %s\n", strerror(errno));  
        return 1;
    } 

	pid_t t_iPid, t_iWpid;

	for(int i=0; i<PLAYER_NUM; ++i)
	{
		t_iPid = fork();
		if(t_iPid < 0)
		{
			cout<< "fork error."<< endl;
			return 1;
		}
		else if(t_iPid == 0)
		{
			cout<< "child "<< t_iPid<< endl;
			sleep(10);
			return 0;
		}
	}

	cout<< "parent"<< endl;
	sleep(20);
	/*
	do
	{ 
		t_iWpid = waitpid(-1, &t_iStat, WNOHANG);
		if(t_iWpid == 0)
		{
			printf("The child process has not exited \n");  
            sleep(1);  
		}
		else if(t_iWpid > 0)
		{
			printf("child %d terminated\n", getpid());
		}
		
		else
		{
			if (WIFEXITED(t_iStat))  
				printf("Child %d terminated normally return status is %d\n",  
					t_iWpid, WEXITSTATUS(t_iStat));  
			else if (WIFSIGNALED(t_iStat));  
				printf("Child %d terminated due to signal %d znot caught\n",  
					t_iWpid, WTERMSIG(t_iStat));  
		}
		
	}while(t_iWpid >= 0);
*/
	return 0;
}