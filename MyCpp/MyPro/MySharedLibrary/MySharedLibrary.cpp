#include "MySharedLibrary.h"

MMyLib::IMySharedLibrary::IMySharedLibrary(string in_sFileName): m_oLibrary(in_sFileName.append(SharedLibrary::suffix()))
{}

MMyLib::IMySharedLibrary::~IMySharedLibrary()
{
	m_oLibrary.unload();
}

MMyLib::IMySharedLibrary::ExecFunc(string in_sFuncName)
{
	Func t_pFunc = (Func) library.getSymbol(in_sFuncName);
	if(!func)
		throw LoadFuncException("Func name not exist.");
	t_pFunc();
}