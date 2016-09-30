#include "MyStdAfx.h"
#include "MyRedis.h"
using namespace MMyLib;

int main(int argc, char *argv[])
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	if(argc != 2)
		cout<< "need id"<< endl;

	int t_iConditionId = atoi(argv[1]);
	//获取id
	LOG_INFO<< t_iConditionId<< " kkk"<< endl;
	cout<< t_iConditionId<< " kkk"<< endl;

	reply t_oReply = g_pRedisConn->run(command("GET") << argv[1] );
	LOG_INFO << "XML path is: " << t_oReply.str() << endl;
	//解析xml
	//执行程序
	return 0;
}