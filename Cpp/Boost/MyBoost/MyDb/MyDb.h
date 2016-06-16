#ifndef __MY_LIB_MY_DB_H_
#define __MY_LIB_MY_DB_H_

#include "../MyStdAfx.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/MySQL/MySQLException.h"

using namespace Poco::Data;  
using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;
//using Poco::StringTokenizer;
using Poco::Data::MySQL::ConnectionException;  
using Poco::Data::MySQL::StatementException;   

namespace MMyLib
{
	class MyDb
	{
	public:
		enum DbType {SQLite, MySQL};

		MyDb():m_pSession(NULL){}
		~MyDb(){};
		int Initialize(DbType in_eDbType, const char* in_sDbName);
		int Uninitialize();
		Session* GetSession();

	template <class T>
		int ExecuteSQL(const char* in_sSQL, T& out_oT)
		{

			LOG_INFO<< in_sSQL;
			out_oT.clear();
			Statement t_oStatement(*m_pSession);
			t_oStatement<< in_sSQL, into(out_oT), now;
			return 0;
		}
	private:
		Session *m_pSession;
	};
};

#endif