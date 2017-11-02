#ifndef __MY_LIB_MY_EXCEPTION_H_
#define __MY_LIB_MY_EXCEPTION_H_

#include "MyStdAfx.h"
#include "Poco/Exception.h"
#include <typeinfo>
using Poco::Exception;

namespace MMyLib
{
	//DB
	POCO_DECLARE_EXCEPTION(Foundation_API, InitializeDbException, Exception)
	POCO_DECLARE_EXCEPTION(Foundation_API, CreateTablesException, Exception)
	POCO_DECLARE_EXCEPTION(Foundation_API, NoRecordException, Exception)

	//SharedLibrary
	POCO_DECLARE_EXCEPTION(Foundation_API, LoadFuncException, Exception)
	POCO_DECLARE_EXCEPTION(Foundation_API, TestException, Exception)

	//Frame
	POCO_DECLARE_EXCEPTION(Foundation_API, XMLPathNoRecordException, Exception)
}


#endif