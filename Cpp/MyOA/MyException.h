#ifndef __MY_OA_MY_EXCEPTION_H_
#define __MY_OA_MY_EXCEPTION_H_

#include "Poco/Exception.h"
#include <typeinfo>

namespace Poco {

POCO_DECLARE_EXCEPTION(Foundation_API, NoRecordException, Exception)
POCO_DECLARE_EXCEPTION(Foundation_API, InitializeDbException, Exception)

}

#endif