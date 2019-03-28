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
            cout<< "sql:"<<pos->second.get_child("sql").data()<< endl;
        }
        t_oMyTable.m_sKeyPre = pos->second.get<string>("<xmlattr>.name");
        t_oMyTable.m_sSql = pos->second.get_child("sql").data();
        m_oTables.push_back(t_oMyTable); 
    }
    return 0;
}

int MyDTS::ImportAllTables()
{
    for(std::vector<MyTable>::iterator it=m_oTables.begin(); it!=m_oTables.end(); ++it)
    {
        if(AnalyseColumn(*it)==-1)
            return -1;

        if(it->m_oColumns.size()<2)
            return -1;

        if(DEBUG)
        {
            cout<<it->m_sKeyPre <<":" <<it->m_sSql <<":" <<it->m_sTableName <<":";
            for(std::vector<std::string>:: iterator it_column=it->m_oColumns.begin(); it_column!=it->m_oColumns.end(); it_column++)
            {
                cout<< *it_column<< endl;
            }
        
        cout<< endl;
        }

        if(it->m_sKeyPre=="t_user1")
        {
            CTUSERS1 t_oCTUSERS1;
            //t_oCTUSERS1.m_sKeyPre = it->m_sKeyPre;
            //t_oCTUSERS1.m_sSql = it->m_sSql;
            //t_oCTUSERS1.m_sTableName = it->m_sTableName;
            //copy(it->m_oColumns.begin(), it->m_oColumns.end(), back_i//nserter(t_oCTUSERS1.m_oColumns));
            ImportTable(*it, t_oCTUSERS1);
        }
        else if(it->m_sKeyPre=="t_user2")
        {
            CTUSERS2 t_oCTUSERS2;
            ImportTable(*it, t_oCTUSERS2);
        }
        else
        {
            
        }
    }
    return 0;
}

template <typename T>
int MyDTS::ImportTable(MyTable &in_oMyTable, T& t)
{
    t.m_sKeyPre = in_oMyTable.m_sKeyPre;
    t.m_sSql = in_oMyTable.m_sSql;
    t.m_sTableName = in_oMyTable.m_sTableName;
    copy(in_oMyTable.m_oColumns.begin(), in_oMyTable.m_oColumns.end(), back_inserter(t.m_oColumns));

    char sql[BUFSIZE]={0};
    sprintf(sql, "%s", t.m_sSql.c_str());
    m_oMyDb.ExecuteSQL(sql, t.m_oVals);
    t.getKeyValues();
    
    for(map<string, map<string, string> >::iterator iti = t.m_oKeyRecords.begin();
        iti!=t.m_oKeyRecords.end(); ++iti)
    {
        string key = iti->first;
        for(map<string, string>::iterator itj = iti->second.begin();
        itj!=iti->second.end(); ++itj)
        {
            string field = itj->first;
            string value = itj->second;
            //if(DEBUG)
            //    cout<< "hset "+ key<< " "<< field<< " "<< value<< endl;
            LOG_INFO("hset %s %s %s", key.c_str(), field.c_str(), value.c_str());
            m_oMyRedis.m_oMyRedisHash.hset(key.c_str(), field.c_str(), value.c_str());
        }
    }
}

/*
template <typename T>
int MyDTS::ImportTable(MyTable& in_oMyTable, std::vector<T>& mytable)
{
    char sql[BUFSIZE]={0};
    sprintf(sql, "%s", in_oMyTable.m_sSql.c_str());
    m_oMyDb.ExecuteSQL(sql, mytable);

    for(typename std::vector<T>::const_iterator it = mytable.begin(); it != mytable.end(); ++it)
    {
        std::cout << (it->template get<0>())
            <<" | " << (it->template get<1>())
            <<" | " << (it->template get<2>())
            << std::endl;

        
        //hset tablename.key column value
        string key = in_oMyTable.m_sKeyPre + (it->template get<0>());
        //int j = 0;
        for(int i=0; i<in_oMyTable.m_oColumns.size();++i)
        {
            string field = in_oMyTable.m_oColumns[i];
            int j = 0;
            string value = it->template get<j>();
            cout<< "hset "+ key<< " "<< field<< " "<< value<< endl;
        }
          
    }
}*/

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
        t_sTableName = t_sSql.substr(1);
    in_oMyTable.m_sTableName = t_sTableName;

    //获取column 
    string::size_type t_iBegin = t_iPos1+strlen("select");
    string::size_type t_iEnd = t_iPos2;
    string t_sColumns = in_sSql.substr(t_iBegin, t_iEnd-t_iBegin);
    t_sColumns = MMyLib::trim(t_sColumns);

    char *t_pToken=strtok((char*)t_sColumns.c_str(),","); 
    t_pToken=strtok(NULL,",");
    while(t_pToken!=NULL) 
    {
        std::string t_sColumn = t_pToken;
        //cout<<t_pToken<<'\n';
        in_oMyTable.m_oColumns.push_back(MMyLib::trim(t_sColumn));
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