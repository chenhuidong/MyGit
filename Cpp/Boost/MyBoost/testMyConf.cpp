#include "MyConf.h"
using namespace MMyLib;

int main()
{
	IMyConf t_oMyConf;
	//ptree t_oPt = t_oMyConf.ReadFile(IMyConf::XML, "conf.xml");
	//ptree t_oPt = t_oMyConf.ReadFile(IMyConf::JSON, "conf.json");
	ptree t_oPt = t_oMyConf.ReadFile(IMyConf::INFO, "conf.info");

	try
	{
		cout<< t_oPt.get<string>("conf.theme")<< endl;
		cout<< t_oPt.get<int>("conf.clock_style")<< endl;
		cout<< t_oPt.get<long>("conf.gui")<< endl;
		cout<< t_oPt.get("conf.no_prop", 100)<< endl;	
		
		BOOST_AUTO(child, t_oPt.get_child("conf.urls"));
		for(BOOST_AUTO(pos, child.begin()); pos!= child.end(); ++pos)
		{
			cout<< pos->second.data()<< ",";
		}
		cout<< endl;
	}
	catch(xml_parser::xml_parser_error &e)
	{
		cout<< e.what()<< endl;
	}
	catch(json_parser::json_parser_error &e)
	{
		cout<< e.what()<< endl;
	}
	catch(info_parser::info_parser_error &e)
	{
		cout<< e.what()<< endl;
	}
	catch(std::exception &e)
	{
		cout<< e.what()<< endl;
	}
	return 0;
}