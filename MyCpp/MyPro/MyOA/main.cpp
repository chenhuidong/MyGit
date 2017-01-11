#include "MyAction.h"

int main(int argc, char* argv[])
{
	MyAction t_oMyAction;
	//sqlite
	//t_oMyAction.Initialize("MyOA.log", MyDb::SQLite, "employee.db");
	
	//mysql
	t_oMyAction.Initialize("MyOA.log", MyDb::MySQL, \
		"host=127.0.0.1;port=3306;user=chenhuidong;password=Chenhd@443420;db=public;compress=true;auto-reconnect=true");
	LOG_INFO<< "MyOA begin.";
	try
	{
		t_oMyAction.InsertData();
		t_oMyAction.SelectData();
		//t_oMyAction.SendEmail();
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
