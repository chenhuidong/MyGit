#include "MyData.h"

void MyData::Initialize(const char* dbname)
{
	// register SQLite connector
    Poco::Data::SQLite::Connector::registerConnector();

    // create a session
    m_pSession = new Session("SQLite", dbname);
}

void MyData::Uninitialize()
{
    // delete a session
    delete m_pSession;
    m_pSession = NULL;
}

Session* MyData::GetSession()
{
	return m_pSession;
}