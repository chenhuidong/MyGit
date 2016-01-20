#ifndef __MY_ANALYSE_RECV_H_
#define __MY_ANALYSE_RECV_H_
#include <iostream>
#include <string>
#include "Poco/StringTokenizer.h"
#include <map>
#include <list>

using Poco::StringTokenizer;


class MyAnalyseRecv
{
public:
	enum MyAnalyseType
	{
		StringToMap,
		XML,
	};
	MyAnalyseRecv(MyAnalyseType t_eMyAnalyseType, std::string t_sRecv) : m_eMyAnalyseType(t_eMyAnalyseType), m_sRecv(t_sRecv){}
	~MyAnalyseRecv(){}

	int AnalyseStringToMap();
	int AnalyseStringToList();
private:
	MyAnalyseType m_eMyAnalyseType;
	std::string m_sRecv;
	std::map<std::string, std::string> m_mapRecv;
	std::list<std::string> m_listRecv;
};

#endif