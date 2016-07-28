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
		StringToList,
		XML,
	};
	MyAnalyseRecv(MyAnalyseType in_eMyAnalyseType, std::string in_sRecv) : m_eMyAnalyseType(in_eMyAnalyseType), m_sRecv(in_sRecv){}
	virtual ~MyAnalyseRecv(){}

	int AnalyseStringToMap();
	int AnalyseStringToList();
	int AnalyseXML();
	int AnalyseJSON();
private:
	MyAnalyseType m_eMyAnalyseType;
	std::string m_sRecv;
	std::map<std::string, std::string> m_mapRecv;
	std::list<std::string> m_listRecv;
};

#endif