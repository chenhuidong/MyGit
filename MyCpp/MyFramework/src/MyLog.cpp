#include "MyStdAfx.h"
#include "MyLog.h"

namespace MMyLib
{
log4cpp::Category* pLog = NULL;

int InitLog(const char * in_sInitFileName)
{
	std::string t_sInitFileName="";
	if(!in_sInitFileName)
		t_sInitFileName = "main";
	else
		t_sInitFileName = in_sInitFileName;
	log4cpp::PropertyConfigurator::configure(t_sInitFileName);
	pLog = &log4cpp::Category::getRoot();
	return 0;
}

int UninitLog()
{
	log4cpp::Category::shutdown();
	return 0;
}

};