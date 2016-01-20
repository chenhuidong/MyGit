#ifndef __MY_ANALYSE_RECV_H_
#define __MY_ANALYSE_RECV_H_
#include <iostream>
#include <string>

class MyAnalyseRecv
{
public:
	MyAnalyseRecv(std::string t_sRecv):m_sRecv(t_sRecv){}
	~MyAnalyseRecv(){}

	int AnalyseToMap();
private:
	std::string m_sRecv;
};

#endif