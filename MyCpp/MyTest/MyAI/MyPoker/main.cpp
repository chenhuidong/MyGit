#include "stdafx.h"
#include "Enum.h"

using namespace mypoker;

int main(int argc, char** argv)
{
	pid_t t_iPid, t_iWpid;
	int   t_iStat; 

	for(int i=0; i<PLAYER_NUM; ++i)
	{
		t_iPid = fork();
		if(t_iPid < 0)
		{
			cout<< "fork error."<< endl;
		}
		else if(t_iPid == 0)
		{
			cout<< "child "<< i<< endl;
			sleep(10);
			return 0;
		}
	}

	cout<< "parent"<< endl;
	while((t_iWpid = waitpid(-1, &t_iStat, WNOHANG)) > 0)
	{ 
		printf("child %d terminated\n", t_iWpid);

		if (WIFEXITED(t_iStat))  
        	printf("Child %d terminated normally return status is %d\n",  
            	t_iWpid, WEXITSTATUS(t_iStat));  
    	else if (WIFSIGNALED(t_iStat));  
    		printf("Child %d terminated due to signal %d znot caught\n",  
            	t_iWpid, WTERMSIG(t_iStat));  
	} 

	return 0;
}