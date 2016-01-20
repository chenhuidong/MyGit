#include "MyAnalyseRecv.h"

int MyAnalyseRecv::AnalyseStringToMap()
{
	m_mRecv.clear();
	StringTokenizer t_oTokenizer(m_sRecv, "|", StringTokenizer::TOK_TRIM);
	
	std::string t_sKey, t_sValue;
	//std::cout<< t_oTokenizer.count()<< std::endl;
	std::size_t t_iSize = t_oTokenizer.count();

	for (std::size_t i=0; i<t_iSize-1; ++i)
	{
		t_sKey=t_oTokenizer[i];
		t_sValue=t_oTokenizer[++i];
		m_mRecv.insert(make_pair(t_sKey, t_sValue));
	}

	for(std::map<std::string, std::string>::iterator it=m_mRecv.begin(); it!=m_mRecv.end(); ++it)
	{
		std::cout<< it->first<< " "<< it->second<< std::endl;
	}
	return 0;
}