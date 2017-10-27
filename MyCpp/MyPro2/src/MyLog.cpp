#include "MyStdAfx.h"
#include "MyLog.h"
using namespace MMyLib;

int Initialize(const char * in_sInitFileName)
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

int Uninitialize()
{
	log4cpp::Category::shutdown();
	return 0;
}