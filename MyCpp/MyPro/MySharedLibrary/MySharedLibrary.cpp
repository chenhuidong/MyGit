#include "MySharedLibrary.h"

MMyLib::IMySharedLibrary::IMySharedLibrary(string in_sPathName): m_oLibrary(m_sPathName), m_sPathName(in_sPathName.append(SharedLibrary::suffix()))
{
	m_oLoader.loadLibrary(m_sPathName);
}

MMyLib::IMySharedLibrary::~IMySharedLibrary()
{
	m_oLibrary.unload();
	m_oLoader.unloadLibrary(m_sPathName);
}

void MMyLib::IMySharedLibrary::ExecFunc(string in_sFuncName)
{
	Func t_pFunc = (Func) m_oLibrary.getSymbol(in_sFuncName);
	if(!t_pFunc)
		throw LoadFuncException("Func name not exist.");
	t_pFunc();
}

void MMyLib::IMySharedLibrary::ExecClassFunc(string in_sClassName, string in_sFuncName)
{
	AbstractPlugin* pPluginA = m_oLoader.create("PluginA");
	pPluginA->HelloWorld();
	m_oLoader.classFor("PluginA").autoDelete(pPluginA);	
}
