#include "MyData.h"

void MyData::Initialize(std::string &dbname)
{
	// register SQLite connector
    Poco::Data::SQLite::Connector::registerConnector();

    // create a session
    m_pSession = new Session("SQLite", dbname);
}