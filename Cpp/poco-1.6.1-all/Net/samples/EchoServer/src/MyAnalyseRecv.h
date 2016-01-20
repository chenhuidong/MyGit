#ifndef __MY_ANALYSE_RECV_H_
#define __MY_ANALYSE_RECV_H_

class MyAnalyseRecv
{
public:
	MyAnalyseRecv():m_sRecv(t_sRecv){}
	~MyAnalyseRecv(){}

	int AnalyseToMap();
private:
	string m_sRecv;
};

#endif