#include "MyConf.h"

ptree& MMyLib::IMyConf::ReadFile(MMyLib::IMyConf::ConfType in_eConfType, string in_sFileName)
{
	switch(in_eConfType)
	{
		case XML:
		{
			read_xml(in_sFileName, m_oPt);
			break;
		}
		case JSON:
		{
			read_json(in_sFileName, m_oPt);
			break;
		}
		case INFO:
		{
			read_info(in_sFileName, m_oPt);
			break;
		}
		default:
		{
			break;
		}
	}
	return m_oPt;
}