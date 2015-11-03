#include "MyDb.h"

int MyDb::Initialize(const char* in_sDbName)
{
    /*
	// register SQLite connector
    Poco::Data::SQLite::Connector::registerConnector();

    // create a session
    m_pSession = new Session("SQLite", in_sDbName);
    */
    Poco::Data::MySQL::Connector::registerConnector();
    m_pSession = new Session(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY,\
     "host=121.42.27.147;port=54321;user=mysql;password=123456;db=public;compress=true;auto-reconnect=true"));

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
