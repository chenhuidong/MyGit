#include "MyFrame.h"
using namespace MMyLib;

int main(int argc, char *argv[])
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	if(argc != 2)
	{
		LOG_ERROR<< "Usage: ./MyFrame taskid."<< endl;
		return SDL_FAILED;
	}

	/*
	int t_pid = fork();	
	if(t_pid < 0)
	{
		LOG_ERROR<< "Fork error"<< endl;
		return SDL_FAILED;
	}
	else if(0 == t_pid)
	{
		*/
	int t_iConditionId = atoi(argv[1]);
		//获取id
	LOG_INFO<< "Begin task "<< t_iConditionId<< "."<< endl;

	LOG_INFO<< "Begin a new task."<< endl;
	IMyFrame t_oMyFrame;
	t_oMyFrame.BeginNewTask(argv[1]);
	/*
	}
	else
	{
		LOG_INFO<< "Continue my task."<< endl;

	}
	*/
	return SDL_OK;
}