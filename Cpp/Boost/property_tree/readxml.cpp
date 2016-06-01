#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/typeof/typeof.hpp> 
#include <iostream>
using namespace std;
using namespace boost::property_tree;

int main()
{
	ptree pt;
	read_xml("conf.xml", pt, xml_parser::no_concat_text | xml_parser::no_comments | xml_parser::trim_whitespace);

	try
	{
		cout<< pt.get<string>("conf.theme")<< endl;
		cout<< pt.get<int>("conf.clock_style")<< endl;
		/*cout<< pt.get<long>("conf.gui")<< endl;
		cout<< pt.get("conf.no_prop", 100)<< endl;	
		
		BOOST_AUTO(child, pt.get_child("conf.urls"));
		for(BOOST_AUTO(pos, child.begin()); pos!= child.end(); ++pos)
		{
			cout<< pos->second.data()<< ",";
		}
		cout<< endl;	*/
	}
	catch(xml_parser::xml_parser_error &e)
	{
		cout<< e.what()<< endl;
	}
	catch(std::exception &e)
	{
		cout<< e.what()<< endl;
	}

	return 0;
}