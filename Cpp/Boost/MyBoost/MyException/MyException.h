#ifndef __MY_LIB_MY_EXCEPTION_H_
#define __MY_LIB_MY_EXCEPTION_H_

#include "Poco/Exception.h"
#include <typeinfo>
using Poco::Exception;

namespace MMyLib
{
	namespace Poco
	{
		POCO_DECLARE_EXCEPTION(Foundation_API, NoRecordException, Exception)
		POCO_DECLARE_EXCEPTION(Foundation_API, TestException, Exception)
	}
};

#endif