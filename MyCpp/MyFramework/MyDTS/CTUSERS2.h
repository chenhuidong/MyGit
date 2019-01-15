#ifndef __C_TUSERS2_H_
#define __C_TUSERS2_H_

#include "MyDb.h"
#include "MyTable.h"

typedef Poco::Tuple<std::string, std::string, std::string, std::string> t_user2;
typedef std::vector<t_user2> t_user2s;

class CTUSERS2 : public MyTable
{
public:
	int getKeyValues()
	{
		for(std::vector<t_user2>::const_iterator it = m_oVals.begin(); it != m_oVals.end(); ++it)
	    {	
	        m_sKey = m_sKeyPre + (it->template get<0>());
	        m_oFieldValues.insert(make_pair(m_oColumns[0], it->template get<1>()));
	        m_oFieldValues.insert(make_pair(m_oColumns[1], it->template get<2>()));
	        m_oFieldValues.insert(make_pair(m_oColumns[2], it->template get<3>()));
	    }
	}
	t_user2s m_oVals;
};

#endif