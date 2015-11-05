#include "MyDb.h"

int MyDb::Initialize(DbType in_eDbType, const char* in_sDbName)
{
    // create a session
    if(SQLite == in_eDbType)
    {
        // register SQLite connector
        Poco::Data::SQLite::Connector::registerConnector();
        m_pSession = new Session("SQLite", in_sDbName);
    }
    else if(MySQL == in_eDbType)
    {
        Poco::Data::MySQL::Connector::registerConnector();
        m_pSession = new Session(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, in_sDbName));
    }
    else
    {
        return -1;
    }

    if(!m_pSession)
    	return -1;
    
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
