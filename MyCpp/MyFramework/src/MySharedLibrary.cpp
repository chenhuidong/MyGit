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

int MMyLib::IMySharedLibrary::ExecFunc(string in_sFuncName)
{
	Func t_pFunc = (Func) m_oLibrary.getSymbol(in_sFuncName);
	if(!t_pFunc)
		throw LoadFuncException("Func name not exist.");
	t_pFunc();
}

AbstractPlugin* MMyLib::IMySharedLibrary::CreateClass(string in_sClassName)
{
	return m_oLoader.create(in_sClassName);
}
