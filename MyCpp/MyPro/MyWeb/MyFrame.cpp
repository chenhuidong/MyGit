#include "MyTask.h"
using namespace MMyLib;

int main(int argc, char *argv[])
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	if(argc != 2)
	{
		LOG_ERROR<< "Usage: ./MyTask taskid."<< endl;
		return SDL_FAILED;
	}

	int t_iConditionId = atoi(argv[1]);
		//获取id
	LOG_INFO<< "Begin task "<< t_iConditionId<< "."<< endl;

	LOG_INFO<< "Begin a new task."<< endl;
	IMyTask t_oMyTask;
	t_oMyTask.BeginNewTask(t_iConditionId);

	return SDL_OK;
}