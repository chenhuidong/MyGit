#include "MyException.h"

namespace Poco {

POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "No record exception")

}