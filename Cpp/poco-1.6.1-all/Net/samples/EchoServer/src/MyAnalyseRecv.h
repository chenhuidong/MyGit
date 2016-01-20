#ifndef __MY_ANALYSE_RECV_H_
#define __MY_ANALYSE_RECV_H_
#include <iostream>
#include <string>

enum MyAnalyseType
{
	StringToMap,
	XML,
}

class MyAnalyseRecv
{
public:
	MyAnalyseRecv(MyAnalyseType t_eMyAnalyseType, std::string t_sRecv) : m_eMyAnalyseType(t_eMyAnalyseType), m_sRecv(t_sRecv){}
	~MyAnalyseRecv(){}

	int AnalyseToMap();
private:
	MyAnalyseType m_eMyAnalyseType;
	std::string m_sRecv;
};

#endif