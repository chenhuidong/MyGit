#ifndef __C_TUSERS1_H_
#define __C_TUSERS1_H_

#include "MyDb.h"
#include "MyTable.h"

typedef Poco::Tuple<std::string, std::string, std::string> t_user1;
typedef std::vector<t_user1> t_user1s;

class CTUSERS1 : public MyTable
{
public:
	int getKeyValues()
	{
		for(std::vector<t_user1>::const_iterator it = m_oVals.begin(); it != m_oVals.end(); ++it)
	    {	
	    	if(0)
	    	{
		        std::cout << (it->template get<0>())
		            <<" | " << (it->template get<1>())
		            <<" | " << (it->template get<2>())
		            << std::endl;
	        }

	        m_sKey = m_sKeyPre + (it->template get<0>());
	        m_oFieldValues.insert(make_pair(m_oColumns[0], it->template get<1>()));
	        m_oFieldValues.insert(make_pair(m_oColumns[1], it->template get<2>()));
	    }
	}
	t_user1s m_oVals;
};

#endif