#include "MyStdAfx.h"
#include "MyRedis.h"
#include "MyConf.h"
#include "MySharedLibrary.h"
using namespace MMyLib;

int main(int argc, char *argv[])
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	if(argc != 2)
	{
		LOG_ERROR<< "usage: ./MyFrame taskid."<< endl;
		return -1;
	}

	int t_iConditionId = atoi(argv[1]);
	//获取id
	LOG_INFO<< "begin task "<< t_iConditionId<< "."<< endl;

	reply t_oReply = g_pRedisConn->run(command("GET")<< (const char*)argv[1]);
	LOG_INFO<< "XML filename is: "<< t_oReply.str()<< endl;
	string t_sFileName = t_oReply.str();

	//解析xml
	IMyConf t_oMyConf;
	ptree* t_pPt = t_oMyConf.ReadFile(IMyConf::XML, t_sFileName);
	string t_sCurLib = t_pPt->get<string>("conf.curlib");
	string t_sCurInterface = t_pPt->get<string>("conf.curinterface");

	LOG_INFO<< "current lib is "<< t_sCurLib<< ". current interface is "<< t_sCurInterface<< "."<< endl;
	
	//执行程序
	IMySharedLibrary t_oProvider(t_sCurLib);
	int t_iReturn = t_oProvider.ExecFunc("hello");
	LOG_INFO<< "return is "<< t_iReturn<< endl;
	return 0;
}