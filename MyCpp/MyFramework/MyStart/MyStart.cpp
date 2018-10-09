#include "MyStart.h"

int MyStart::InitializeAll()
{
	std::string initFileName = "MyLog.properties";
	InitLog(initFileName.c_str());
	LOG_INFO("initialize all begin.");
	m_oMyDb.Initialize((MMyLib::MyDb::DbType)0, "testMyDb.db");
	LOG_INFO("initialize all end.");
}

int MyStart::UninitializeAll()
{
	LOG_INFO("uninitialize all begin.");
	m_oMyDb.Uninitialize();
	UninitLog();
	LOG_INFO("uninitialize all begin.");
}

int MyStart::ChooseTask()
{
	system("clear");
	cout<< endl;
	cout<< endl;
	cout<< endl;
	cout<< endl;
	std::cout <<"                     ";
	cout<< "Please choose the task you want to start:"<<endl;
	m_oMyDb.ExecuteSQL("select distinct TASK_CODE,TASK from START_PARAMS where VALID_TAG = '0' order by TASK_CODE", m_oTaskParams);
	for (task_params::const_iterator it = m_oTaskParams.begin(); it != m_oTaskParams.end(); ++it)
    {
    	std::cout <<"                                        ";
        std::cout << it->get<0>() << 
            ". " << it->get<1>() << std::endl;
    }
    int line = 6+m_oTaskParams.size();
    char str[40]={0};
    sprintf(str,"\033[%d;%dH", line ,41);
    //fflush(stdout);
    cout<<str;
    int t_iInput = 1;
    cin>> t_iInput;
    std::cout <<"                                        ";
    if(t_iInput>m_oTaskParams.size())
    {
    	cout<< "your input is wrong."<< endl;
    	return -1;
    }
	
    cout<< "begin "<< t_iInput<< ". "<< m_oTaskParams[t_iInput-1].get<1>()<< endl;
    return 0;
}


int main(int argc, char** argv)
{
	
	//ExecuteSQL(select TASK_CODE,TASK,STEP_CODE,STEP,PROCESS_NO,CHANNEL_FIELD,LIB_NAME,FUNC_NAME from START_PARAMS where VALID_TAG = '0');
	MyStart t_oMyStart;
	t_oMyStart.InitializeAll();
	LOG_INFO("begin.");
	t_oMyStart.ChooseTask();

	LOG_INFO("end.");
	t_oMyStart.UninitializeAll();
}