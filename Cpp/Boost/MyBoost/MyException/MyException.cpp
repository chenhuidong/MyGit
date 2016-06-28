#include "MyException.h"

namespace MMyLib
{
	Poco::POCO_IMPLEMENT_EXCEPTION(InitializeDbException, Exception, "Initialize db failed exception")
	Poco::POCO_IMPLEMENT_EXCEPTION(CreateTablesException, Exception, "Create tables failed exception")
	Poco::POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "No record exception")
	Poco::POCO_IMPLEMENT_EXCEPTION(TestException, Exception, "Test exception")
}
