#include "MyDb.h"

int MMyLib::IMyDb::Initialize(DbType in_eDbType, const char* in_sDbName)
{
    // create a session
    if(IMyDb::SQLite == in_eDbType)
    {
        // register SQLite connector
        LOG_INFO("initialize sqlite begin.\n");

        Poco::Data::SQLite::Connector::registerConnector();
        m_pSession = new Session("SQLite", in_sDbName);
        LOG_INFO("initialize sqlite end.\n");
    }
    else if(IMyDb::MySQL == in_eDbType)
    {
        LOG_INFO("initialize mysql begin.\n");
        Poco::Data::MySQL::Connector::registerConnector();
        m_pSession = new Session(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, in_sDbName));
        LOG_INFO("initialize mysql end.\n");
    }
    else
    {
        throw InitializeDbException("Initialize db failed.");
    }

    if(!m_pSession)
    	throw InitializeDbException("Initialize db failed.");
    
    return 0;
}

int MMyLib::IMyDb::Uninitialize()
{
    // delete a session
    LOG_INFO("Uninitialize.\n");
    delete m_pSession;
    m_pSession = NULL;
}

Session* MMyLib::IMyDb::GetSession()
{
	return m_pSession;
}