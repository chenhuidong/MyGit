#ifndef __MY_LIB_MY_EXCEPTION_H_
#define __MY_LIB_MY_EXCEPTION_H_

#include "MyStdAfx.h"
#include "Poco/Exception.h"
#include <typeinfo>
using Poco::Exception;

namespace MMyLib
{
	POCO_DECLARE_EXCEPTION(Foundation_API, NoRecordException, Exception)
	POCO_DECLARE_EXCEPTION(Foundation_API, TestException, Exception)
}


#endif