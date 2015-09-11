#ifndef __MY_OA_MY_DATA_H_
#define __MY_OA_MY_DATA_H_

#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/StringTokenizer.h"


#include <vector>
#include <iostream>


using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;
using Poco::StringTokenizer;

class MyData
{
public:
	MyData():m_pSession(NULL){}
	~MyData(){};
	int Initialize(const char* in_sDbName);
	int Uninitialize();
	Session* GetSession();

	template <class T>
	int ExecuteSQL(const char* in_sSQL, T& out_oT)
	{
		//std::cout<< in_sSQL<< std::endl;
		Statement t_oStatement(*m_pSession);
    	t_oStatement<< in_sSQL, into(out_oT), now;
    	return 0;
	}
private:
	Session *m_pSession;
};

#endif