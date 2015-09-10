#ifndef __MY_OA_MY_DATA_H_
#define __MY_OA_MY_DATA_H_

#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include <vector>
#include <iostream>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

class MyData
{
public:
	MyData():m_pSession(NULL){}
	~MyData(){};
	int Initialize(const char* in_sDbName);
	int Uninitialize();
	Session* GetSession();

	int ExecuteSQL(const char* in_sSQL, Employees &out_oEmployees);
private:
	Session *m_pSession;
};

#endif