#include "MySharedLibrary.h"

MMyLib::IMySharedLibrary::IMySharedLibrary(string in_sFileName): m_oLibrary(in_sFileName.append(SharedLibrary::suffix())), m_sFileName(in_sFileName.append(SharedLibrary::suffix()))
{
	m_oLoader.loadLibrary(in_sFileName.append(SharedLibrary::suffix()));
}

MMyLib::IMySharedLibrary::~IMySharedLibrary()
{
	m_oLibrary.unload();
	loader.unloadLibrary(m_sFileName);
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
	AbstractPlugin* pPluginA = loader.create("PluginA");
	std::cout << pPluginA->HelloWorld() << std::endl;
	loader.classFor("PluginA").autoDelete(pPluginA);	
}