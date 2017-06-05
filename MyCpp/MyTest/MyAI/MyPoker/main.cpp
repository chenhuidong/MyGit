#include "stdafx.h"
#include "Enum.h"

using namespace mypoker;

int main(int argc, char** argv)
{
	for(int i=0; i<PLAYER_NUM; ++i)
	{
		pid_t pid = fork();
		if(pid < 0)
		{
			cout<< "fork error."<< endl;
		}
		else if(pid == 0)
		{
			cout<< "child "<< i<< endl;
			return 0;
		}
	}

	cout<< "parent"<< endl;
	return 0;
}