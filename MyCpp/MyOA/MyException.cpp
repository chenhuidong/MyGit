#include "MyException.h"

namespace Poco {

POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "No record exception")
POCO_IMPLEMENT_EXCEPTION(InitializeDbException, Exception, "Initialize db failed exception")
POCO_IMPLEMENT_EXCEPTION(CreateTablesException, Exception, "Create tables failed exception")

}