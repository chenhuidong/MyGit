#include "MyStdAfx.h"
using namespace MMyLib;

int main(int argc, char *argv[])
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	if(argc != 2)
		cout<< "need id"<< endl;
	
	int t_iConditionId = atoi(argv[1]);
	//获取id
	LOG_INFO<< t_iConditionId<< " kkk"<< endl;
	//解析xml
	//执行程序
	return 0;
}