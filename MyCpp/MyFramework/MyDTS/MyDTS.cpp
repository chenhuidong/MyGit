#include "MyDTS.h"

int MyDTS::InitializeAll()
{
	std::string initFileName = "MyLog.properties";
	InitLog(initFileName.c_str());
	LOG_INFO("initialize all begin.");
	m_oMyDb.Initialize((MMyLib::IMyDb::DbType)0, "testMyDb.db");
    m_oMyRedis.InitMyRedis("172.17.138.176:7000");
	LOG_INFO("initialize all end.");
}

int MyDTS::UninitializeAll()
{
	LOG_INFO("uninitialize all begin.");
	m_oMyDb.Uninitialize();
	UninitLog();
	LOG_INFO("uninitialize all end.");
}


/*
int MyDTS::BeginTask(int in_iTaskCode)
{
	char sql[BUFSIZE]={0};
	sprintf(sql,"select TASK_CODE, TASK, STEP_CODE, STEP, PROCESS_NO, CHANNEL_FIELD, LIB_NAME, FUNC_NAME from START_PARAMS where VALID_TAG = '0' and TASK_CODE = %d order by STEP_CODE", in_iTaskCode);
	m_oMyDb.ExecuteSQL(sql, m_oTaskParamTotals);
*/	/*for (task_paramtotals::const_iterator it = m_oTaskParamTotals.begin(); it != m_oTaskParamTotals.end(); ++it)
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

/*    for (task_paramtotals::const_iterator it = m_oTaskParamTotals.begin(); it != m_oTaskParamTotals.end(); ++it)
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
*/

int MyDTS::AnalyseConf(string in_sConfName)
{
    ptree* t_pPt = m_oMyConf.ReadFile(IMyConf::XML, in_sConfName.c_str());
    BOOST_AUTO(child, t_pPt->get_child("conf.tables"));
    for(BOOST_AUTO(pos, child.begin()); pos!= child.end(); ++pos)
    {
        MyTable t_oMyTable;
        if(DEBUG)
        {
            cout<< "key_pre:"<< pos->second.get<string>("<xmlattr>.name")<< endl;
            //cout<< pos->second.get<string>("<xmlattr>.key")<< endl;
            //cout<< "sql:"<<pos->second.get_child("sql").data()<< endl;
        }
        t_oMyTable.m_sKeyPre = pos->second.get<string>("<xmlattr>.name");
        t_oMyTable.m_sSql = pos->second.get_child("sql").data();
        m_oTables.push_back(t_oMyTable); 
        //m_oSqls.push_back(pos->second.data());
    }

    return 0;
}

int MyDTS::ImportAllTables()
{
    for(std::vector<MyTable>::iterator it=m_oTables.begin(); it!=m_oTables.end(); it++)
    {
        //std::vector<std::string> t_oColumn;
        if(AnalyseColumn(*it)==-1)
            return -1;

        if(DEBUG)
        {
            for(std::vector<std::string>:: iterator it_column=it->m_oColumns.begin(); it_column!=it->m_oColumns.end(); it_column++)
            {
                cout<< *it_column<< endl;
            }
        
        cout<< endl;
        }

        if(it->m_oColumns.size()<2)
            return -1;

        //std::string t_sKey = t_oColumn[0];
        // hset tablename.key column value
               
    }

    return 0;
}

//int MyDTS::AnalyseColumn(std::string in_sSql, std::vector<std::string> & out_oColunm)
int MyDTS::AnalyseColumn(MyTable &in_oMyTable)
{
    string in_sSql = in_oMyTable.m_sSql;

    //cout<< in_sSql<< endl;
    string::size_type t_iPos1 = in_sSql.find("select");
    if(t_iPos1 == in_sSql.npos)
        return -1;
    
    string::size_type t_iPos2 = in_sSql.find("from");
    if(t_iPos2 == in_sSql.npos)
        return -1;

    //获取表名
    std::string t_sSql = in_sSql.substr(t_iPos2+4);
    string::size_type t_iPos3 = t_sSql.find(" ");
    string t_sTableName;
    if(t_iPos2 == t_sSql.npos)
        t_sTableName = t_sSql.substr(0, t_iPos3);
    else
        t_sTableName = t_sSql;
    in_oMyTable.m_sTableName = t_sTableName;

    //获取column 
    string::size_type t_iBegin = t_iPos1+strlen("select");
    string::size_type t_iEnd = t_iPos2;
    string t_sColumn = in_sSql.substr(t_iBegin, t_iEnd-t_iBegin);
    cout<< t_sColumn << endl;

    char *t_pToken=strtok((char*)t_sColumn.c_str(),","); 
    while(t_pToken!=NULL) 
    {
        //cout<<t_pToken<<'\n';
        //out_oColunm.push_back(t_pToken);
        in_oMyTable.m_oColumns.push_back(t_pToken);
        t_pToken=strtok(NULL,",");
    }

    return 0;
}

int main(int argc, char** argv)
{	
	MyDTS t_oMyDTS;
	t_oMyDTS.InitializeAll();
    LOG_INFO("begin.");
	//LOG_INFO("begin. %d %s", argc, argv[1]);
    t_oMyDTS.AnalyseConf("O2R.xml");

    if(t_oMyDTS.ImportAllTables()==-1)
        return -1;


	LOG_INFO("end.");
	t_oMyDTS.UninitializeAll();

    return 0;
}