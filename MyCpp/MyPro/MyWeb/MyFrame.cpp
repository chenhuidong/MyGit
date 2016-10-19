#include "MyFrame.h"

MMyLib::IMyFrame::IMyFrame()
{
}

MMyLib::IMyFrame::~IMyFrame()
{
}

string& MMyLib::IMyFrame::GetXMLPath(const char* in_sConditionId)
{
	reply t_oReply = MMyLib::g_pRedisConn->run(command("GET")<< in_sConditionId);
	LOG_INFO<< "XML filename is: "<< t_oReply.str()<< "."<< endl;
	m_sXMLPath = t_oReply.str();
	if(0 == m_sXMLPath.length())
	{
		LOG_ERROR<< "Condition id "<< in_sConditionId<< " XML path does not exist."<< endl;
		throw XMLPathNoRecordException("xml path from redis no exist.");
	}
	return m_sXMLPath;
}

ptree* MMyLib::IMyFrame::ParseXML()
{
	return m_oMyConf.ReadFile(IMyConf::XML, m_sXMLPath.c_str());
}

int MMyLib::IMyFrame::BeginNewTask(const char* in_sConditionId)
{
	int t_iReturn = SDL_OK;
	//reply t_oReply = g_pRedisConn->run(command("GET")<< (const char*)argv[1]);
	//LOG_INFO<< "XML filename is: "<< t_oReply.str()<< "."<< endl;
	//string t_sFileName = t_oReply.str();
	
	GetXMLPath(in_sConditionId);

	//解析xml
	//IMyConf t_oMyConf;
	//ptree* t_pPt = t_oMyConf.ReadFile(IMyConf::XML, t_sFileName.c_str());
	ptree* t_pPt = ParseXML();
	string t_sCurLib = t_pPt->get<string>("conf.curlib");
	string t_sCurInterface = t_pPt->get<string>("conf.curinterface");

	LOG_INFO<< "Current lib is "<< t_sCurLib<< ". Current interface is "<< t_sCurInterface<< "."<< endl;
	
	//执行程序
	IMySharedLibrary t_oProvider(t_sCurLib);
	do
	{
		t_iReturn = t_oProvider.ExecFunc(t_sCurInterface);
		LOG_INFO<< "Return code is "<< t_iReturn<< "."<< endl;
		sleep(1);
	}while(t_iReturn == SDL_OK);

	return t_iReturn;
}
