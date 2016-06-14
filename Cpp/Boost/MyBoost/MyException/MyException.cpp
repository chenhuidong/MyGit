#include "MyException.h"

namespace Poco 
{
	POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "No record exception")
	POCO_IMPLEMENT_EXCEPTION(TestException, Exception, "Test exception")
}