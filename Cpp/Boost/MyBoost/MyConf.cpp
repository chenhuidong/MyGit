#include "MyConf.h"

ptree& IMyConf::ReadFile(ConfType in_eConfType, string in_sFileName)
{
	swich(in_eConfType)
	{
		case XML:
		{
			read_xml(in_sFileName, m_oPt, xml_parser::no_concat_text | xml_parser::no_comments | xml_parser::trim_whitespace);
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