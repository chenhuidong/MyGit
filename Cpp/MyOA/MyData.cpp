#include "MyData.h"

int MyData::Initialize(const char* in_sDbName)
{
	// register SQLite connector
    Poco::Data::SQLite::Connector::registerConnector();

    // create a session
    m_pSession = new Session("SQLite", in_sDbName);

    if(!m_pSession)
    	return -1;
    
    return 0;
}

int MyData::Uninitialize()
{
    // delete a session
    delete m_pSession;
    m_pSession = NULL;
}

Session* MyData::GetSession()
{
	return m_pSession;
}