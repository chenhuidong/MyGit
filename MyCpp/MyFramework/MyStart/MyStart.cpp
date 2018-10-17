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
	int t_iInput = -1;
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
	while(-1==t_iInput)
	{
	    std::cout <<"                                 ";
	    cout<< "choose:";
	    
	    char str[40]={0};
	    sprintf(str,"\033[%d;%dH", line ,41);
	    cout<<str;
	    cin>> t_iInput;
	    std::cout <<"                                        ";
	    if(t_iInput>m_oTaskParams.size())
	    {
	    	cout<< "your input is wrong. please reinput."<< endl;
	    	t_iInput = -1;
	    }
	    line=line+2;
	}
	
    cout<< "begin "<< t_iInput<< ". "<< m_oTaskParams[t_iInput-1].get<1>()<< endl;
    return t_iInput;
}

int MyStart::BeginTask(int in_iTaskCode)
{
	char sql[BUFSIZE]={0};
	sprintf(sql,"select TASK_CODE, TASK, STEP_CODE, STEP, PROCESS_NO, CHANNEL_FIELD, LIB_NAME, FUNC_NAME from START_PARAMS where VALID_TAG = '0' and TASK_CODE = %d order by STEP_CODE", in_iTaskCode);
	m_oMyDb.ExecuteSQL(sql, m_oTaskParamTotals);
	/*for (task_paramtotals::const_iterator it = m_oTaskParamTotals.begin(); it != m_oTaskParamTotals.end(); ++it)
    {
    	std::cout <<"                                        ";
        std::cout << it->get<0>() 
            <<" | " << it->get<1>() 
            <<" | " << it->get<2>()
            <<" | " << it->get<3>()
            <<" | " << it->get<4>()
            <<" | " << it->get<5>()
            <<" | " << it->get<6>()
            <<" | " << it->get<7>()
            << std::endl;
    }*/

    for (task_paramtotals::const_iterator it = m_oTaskParamTotals.begin(); it != m_oTaskParamTotals.end(); ++it)
    {
    	int t_iStepCode = it->get<2>();
    	string t_sStep = it->get<3>();
        string t_sLibName = it->get<6>();
        string t_sFuncName = it->get<7>();
        std::cout <<"                                        ";
        cout<< "begin step "
        	<< t_iStepCode<< ". "
        	<< t_sStep<< " "
        	<< t_sLibName<< " "
        	<< t_sFuncName << std::endl;
        LOG_INFO("begin step %d %s %s %s", t_iStepCode, t_sStep.c_str(), t_sLibName.c_str(), t_sFuncName.c_str());
        IMySharedLibrary t_oProvider(t_sLibName);
		t_oProvider.ExecFunc(t_sFuncName);
    }
}

int main(int argc, char** argv)
{	
	MyStart t_oMyStart;
	t_oMyStart.InitializeAll();
	LOG_INFO("begin.");
	int t_iInput = t_oMyStart.ChooseTask();

	t_oMyStart.BeginTask(t_iInput);
	LOG_INFO("end.");
	t_oMyStart.UninitializeAll();
}