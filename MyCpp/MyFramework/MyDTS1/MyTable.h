#ifndef __MY_TABLE_H_
#define __MY_TABLE_H_

class MyTable
{
public:
	std::string			m_sKeyPre;
	//std::string			m_sKey;
	std::string			m_sSql;
	std::string			m_sTableName;
	std::vector<string> m_oColumns;
	std::map<string, string> m_oFieldValues;
	std::map<string, std::map<string, string> >	m_oKeyRecords;	
};

#endif