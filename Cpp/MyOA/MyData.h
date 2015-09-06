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

struct Employee
{
	int			empno;
    std::string name;
    std::string email;
};

class MyData
{
public:
	void Initialize(const char* dbname);
	Session *m_pSession;
};

#endif