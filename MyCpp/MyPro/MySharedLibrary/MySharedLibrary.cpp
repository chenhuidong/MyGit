#include "MySharedLibrary.h"

MMyLib::IMySharedLibrary::IMySharedLibrary(string in_sFileName): m_oLibrary(in_sFileName.append(SharedLibrary::suffix()))
{}

MMyLib::IMySharedLibrary::~IMySharedLibrary()
{
	m_oLibrary.unload();
}

void MMyLib::IMySharedLibrary::ExecFunc(string in_sFuncName)
{
	Func t_pFunc = (Func) m_oLibrary.getSymbol(in_sFuncName);
	//if(!t_pFunc)
	//	throw LoadFuncException("Func name not exist.");
	t_pFunc();
}