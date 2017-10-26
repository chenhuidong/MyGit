#include "MyConf.h"

MMyLib::IMyConf::IMyConf()
{
	m_pPt = new ptree;
}

MMyLib::IMyConf::~IMyConf()
{
	delete m_pPt;
}

ptree* MMyLib::IMyConf::GetPtr()
{
	return m_pPt;
}

ptree* MMyLib::IMyConf::ReadFile(MMyLib::IMyConf::ConfType in_eConfType, const char* in_sFileName)
{
	switch(in_eConfType)
	{
		case MMyLib::IMyConf::XML:
		{
			read_xml(in_sFileName, *m_pPt);
			break;
		}
		case MMyLib::IMyConf::JSON:
		{
			read_json(in_sFileName, *m_pPt);
			break;
		}
		case MMyLib::IMyConf::INFO:
		{
			read_info(in_sFileName, *m_pPt);
			break;
		}
		default:
		{
			m_pPt = NULL;
			break;
		}
	}
	return m_pPt;
}