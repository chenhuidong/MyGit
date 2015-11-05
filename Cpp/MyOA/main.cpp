#include "MyAction.h"

int main(int argc, char* argv[])
{
	MyAction t_oMyAction;
	//sqlite
	//t_oMyAction.Initialize("MyOA.log", DbType::SQLite, "employee.db");
	
	//mysql
	t_oMyAction.Initialize("MyOA.log", MyDb::MySQL, \
		"host=121.42.27.147;port=54321;user=mysql;password=123456;db=public;compress=true;auto-reconnect=true");

	try
	{
		LOG_INFO<< "MyOA begin.";
		t_oMyAction.Install();
		//t_oMyAction.InsertData();
		t_oMyAction.SelectData();
		t_oMyAction.SendEmail();
		t_oMyAction.Uninitialize();
		LOG_INFO<< "MyOA end.";
	}
    catch (Poco::NoRecordException& exc)
    {
    	t_oMyAction.Uninitialize();
        LOG_ERROR << exc.displayText();
        return -1;
    }
    catch (Exception& exc)
	{
		t_oMyAction.Uninitialize();
		LOG_ERROR<< exc.displayText();
		return -1;
	}
	return 0;
}
