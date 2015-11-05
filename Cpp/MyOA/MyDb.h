#ifndef __MY_OA_MY_DB_H_
#define __MY_OA_MY_DB_H_

#include "../stdafx.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/MySQL/MySQLException.h"  
//#include "Poco/StringTokenizer.h"

using namespace Poco::Data;  
using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;
//using Poco::StringTokenizer;
using Poco::Data::MySQL::ConnectionException;  
using Poco::Data::MySQL::StatementException; 

enum DbType {MyOA_SQLite, MyOA_MySQL};

class MyDb
{
public:
	MyDb():m_pSession(NULL){}
	~MyDb(){};
	int Initialize(DbType in_eDbType, const char* in_sDbName);
	int Uninitialize();
	Session* GetSession();

	template <class T>
	int ExecuteSQL(const char* in_sSQL, T& out_oT)
	{
		//std::cout<< in_sSQL<< std::endl;
		out_oT.clear();
		Statement t_oStatement(*m_pSession);
    	t_oStatement<< in_sSQL, into(out_oT), now;
    	return 0;
	}
private:
	Session *m_pSession;
};
#endif