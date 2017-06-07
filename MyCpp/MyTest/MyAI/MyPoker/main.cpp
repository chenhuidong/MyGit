#include "stdafx.h"
#include "Enum.h"

using namespace mypoker;
/*
static void sig_handler(int)
{
	pid_t t_iWpid;
	int   t_iStat; 

    while( (t_iWpid = waitpid(-1,&t_iStat,WNOHANG)) > 0)  
    {  
      if ( WIFEXITED(t_iStat) )  
      {  
          printf("child process revoked. pid[%6d], exit code[%d]\n",t_iWpid,WEXITSTATUS(t_iStat));  
      }  
      else  
         printf("child process revoked.but ...\n");  
    } 
} 
*/
int main(int argc, char** argv)
{
	/*
	if(signal(SIGCHLD, sig_handler) == SIG_ERR)  
    {  
        printf("signal error : %s\n", strerror(errno));  
        return 1;
    } 
	*/
	pid_t t_iPid, t_iWpid;
	int   t_iStat; 
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
			cout<< "child "<< getpid()<< endl;
			sleep(5);
			return 0;
		}
	}

	cout<< "parent"<< endl;

	do
	{ 
		t_iWpid = waitpid(-1, &t_iStat, WNOHANG);
		if(t_iWpid == 0)
		{
			//printf("The child process has not exited \n");  
            sleep(1);  
		}
		else if(t_iWpid > 0)
		{
			printf("child %d terminated\n", t_iWpid);
		}
		//else
		//{
		//	if (WIFEXITED(t_iStat))  
		//		printf("Child %d terminated normally return status is %d\n",  
		//			t_iWpid, WEXITSTATUS(t_iStat));  
		//	else if (WIFSIGNALED(t_iStat));  
		//		printf("Child %d terminated due to signal %d znot caught\n",  
		//			t_iWpid, WTERMSIG(t_iStat));  
		//}
	}while(t_iWpid >= 0);

	return 0;
}