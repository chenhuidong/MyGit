#include "MyAction.h"

int main(int argc, char* argv[])
{
	MyAction t_oMyAction;
	t_oMyAction.Initialize("MyOA.log", "employee.db");
	try
	{
		LOG_INFO<< "MyOA begin.";
		t_oMyAction.Install();
		//t_oMyAction.InsertData();
		t_oMyAction.SelectData();
		t_oMyAction.SendEmail();
		t_oMyAction.UninitializeDb();
		LOG_INFO<< "MyOA end.";
	}
    catch (Poco::NoRecordException& exc)
    {
        LOG_ERROR << exc.displayText();
        t_oMyAction.UninitializeDb();
        return -1;
    }
    catch (Exception& exc)
	{
		LOG_ERROR<< exc.displayText();
		return 1;
	}
	return 0;
}
