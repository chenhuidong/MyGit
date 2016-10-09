#include "MyFrame.h"

MMyLib::IMyFrame::IMyFrame()
{
}

MMyLib::IMyFrame::~IMyFrame()
{
}

int MMyLib::IMyFrame::GetXMLPath(const char* in_sConditionId)
{
	reply t_oReply = g_pRedisConn->run(command("GET")<< in_sConditionId);
	LOG_INFO<< "XML filename is: "<< t_oReply.str()<< "."<< endl;
	m_sXMLPath = t_oReply.str();
	if(0 == m_sXMLPath.length())
	{
		LOG_ERROR<< "Condition id "<< in_sConditionId<< " XML path does not exist."<< endl;
			throw 
	}
}

string& MMyLib::IMyFrame::GetCurLib()
{

}

string& MMyLib::IMyFrame::GetCurInterface()
{

}