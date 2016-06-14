#include "MyException.h"

MMyLib::Poco::POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "No record exception")
MMyLib::Poco::POCO_IMPLEMENT_EXCEPTION(TestException, Exception, "Test exception")
