#include "MyData.h"

template <class T>
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

template <class T>
int MyData::Uninitialize()
{
    // delete a session
    delete m_pSession;
    m_pSession = NULL;
}

template <class T>
Session* MyData::GetSession()
{
	return m_pSession;
}

template <class T>
int MyData::ExecuteSQL(const char* in_sSQL, T &out_oT)
{
    Statement t_oStatement(*m_pSession);
    t_oStatement<< in_sSQL, into(out_oT), now;
    return 0;
}