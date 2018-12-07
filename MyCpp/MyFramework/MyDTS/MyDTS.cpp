#include "MyDTS.h"

int MyDTS::InitializeAll()
{
	std::string initFileName = "MyLog.properties";
	InitLog(initFileName.c_str());
	LOG_INFO("initialize all begin.");
	m_oMyDb.Initialize((MMyLib::MyDb::DbType)0, "testMyDb.db");
    m_oMyRedis.InitMyRedis("172.17.138.176:7000");
	LOG_INFO("initialize all end.");
}

int MyDTS::UninitializeAll()
{
	LOG_INFO("uninitialize all begin.");
	m_oMyDb.Uninitialize();
	UninitLog();
	LOG_INFO("uninitialize all begin.");
}



int MyDTS::BeginTask(int in_iTaskCode)
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
        
        //MMyLib::g_pRedisConn->run(command("auth")<< "443420");
        string t_sKey = "";
        t_sKey += "START_PARAMS" + itoa(t_iStepCode);
        m_oMyRedis.m_oMyRedisString.set("stu_1234567","chenhuidong");
        //m_oMyRedis.m_oMyRedisHash.hset("stu_1234567","name","chenhuidong");
        //reply t_oReply = MMyLib::g_pRedisConn->run(command("hset")<< t_sKey<< "STEP_CODE"<< t_iStepCode);
        //MMyLib::g_pRedisConn->run(command("hset")<< t_sKey<< "STEP"<< t_sStep);
        //reply t_oReply = MMyLib::g_pRedisConn->run(command("hget") << t_sKey<< "STEP_CODE");
        //std::cout << "step_code1 is: " << t_oReply.str() << std::endl;
    }
}

int main(int argc, char** argv)
{	
	MyDTS t_oMyDTS;
	t_oMyDTS.InitializeAll();
    LOG_INFO("begin.");
	//LOG_INFO("begin. %d %s", argc, argv[1]);

	t_oMyDTS.BeginTask(1);

	LOG_INFO("end.");
	t_oMyDTS.UninitializeAll();
}