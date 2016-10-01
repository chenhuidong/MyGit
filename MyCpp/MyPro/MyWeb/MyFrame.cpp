#include "MyStdAfx.h"
#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char *argv[])
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	if(argc != 2)
		LOG_ERROR<< "MyFrame taskid."<< endl;

	int t_iConditionId = atoi(argv[1]);
	//获取id
	LOG_INFO<< "begin task "<< t_iConditionId<< "."<< endl;
	cout<< "begin task "<< t_iConditionId<< "."<< endl;

	reply t_oReply = g_pRedisConn->run(command("GET") << (const char*)argv[1] );
	LOG_INFO << "XML filename is: " << t_oReply.str() << endl;
	//解析xml
	//执行程序
	return 0;
}