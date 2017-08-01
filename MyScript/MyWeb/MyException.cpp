#include "MyException.h"

namespace MMyLib
{
	//DB
	POCO_IMPLEMENT_EXCEPTION(InitializeDbException, Exception, "Initialize db failed exception")
	POCO_IMPLEMENT_EXCEPTION(CreateTablesException, Exception, "Create tables failed exception")
	POCO_IMPLEMENT_EXCEPTION(NoRecordException, Exception, "No record exception")

	//SharedLibrary
	POCO_IMPLEMENT_EXCEPTION(LoadFuncException, Exception, "Load func exception")
	POCO_IMPLEMENT_EXCEPTION(TestException, Exception, "Test exception")

	//Frame
	POCO_IMPLEMENT_EXCEPTION(XMLPathNoRecordException, Exception, "XML path no record")
}
