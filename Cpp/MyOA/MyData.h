#ifndef __MY_OA_MY_DATA_H_
#define __MY_OA_MY_DATA_H_

#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/StringTokenizer.h"
#include "Poco/String.h"

#include <vector>
#include <iostream>


using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;
using Poco::StringTokenizer;

typedef Poco::Tuple<int, std::string, std::string> Employee;
typedef std::vector<Employee> Employees;

class MyData
{
public:
	MyData():m_pSession(NULL){}
	~MyData(){};
	int Initialize(const char* in_sDbName);
	int Uninitialize();
	Session* GetSession();

	template <class T>
	int ExecuteSQL(const char* in_sSQL, T& inout_oT)
	{
		StringTokenizer tokenizer(in_sSQL, " ", StringTokenizer::TOK_TRIM);
		std::string t_sOperateType = *tokenizer.begin();
		t_sOperateType = Poco::toUpper(t_sOperateType);
		std::cout<< t_sOperateType<< std::endl;

		//cout<<pOperateType<<endl;
		/*
		Statement t_oStatement(*m_pSession);
    	t_oStatement<< in_sSQL, use(in_oT), into(out_oT), now;
    	*/
    	return 0;
	}
private:
	Session *m_pSession;
};

#endif