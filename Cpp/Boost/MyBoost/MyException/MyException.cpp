#include "MyException.h"


MMyLib::POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "No record exception")
MMyLib::POCO_IMPLEMENT_EXCEPTION(TestException, Exception, "Test exception")
