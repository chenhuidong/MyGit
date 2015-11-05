#include "MyDb.h"

int MyDb::Initialize(DbType in_eDbType, const char* in_sDbName)
{
    // create a session
    if(MyOA_SQLite == in_eDbType)
    {
        // register SQLite connector
        LOG_INFO<< "initialize sqlite begin.";

        Poco::Data::SQLite::Connector::registerConnector();
        m_pSession = new Session("SQLite", in_sDbName);
        LOG_INFO<< "initialize sqlite end.";
    }
    else if(MyOA_MySQL == in_eDbType)
    {
        LOG_INFO<< "initialize mysql begin.";
        Poco::Data::MySQL::Connector::registerConnector();
        //m_pSession = new Session(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, in_sDbName));
        LOG_INFO<< "initialize mysql end.";
    }
    else
    {
        throw Poco::InitializeDbException("Initialize db failed.");
    }

    if(!m_pSession)
    	throw Poco::InitializeDbException("Initialize db failed.");
    
    return 0;
}

int MyDb::Uninitialize()
{
    // delete a session
    delete m_pSession;
    m_pSession = NULL;
}

Session* MyDb::GetSession()
{
	return m_pSession;
}

