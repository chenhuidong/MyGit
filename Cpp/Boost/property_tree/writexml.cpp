#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/typeof/typeof.hpp> 
#include <iostream>
using namespace std;
using namespace boost::property_tree;

int main()
{
	ptree pt;
	read_xml("conf1.xml", pt);

	pt.put("conf.theme", "Matrix Reloaded");
	pt.put("conf.clock_style", 12);
	pt.put("conf.gui", 0);
	pt.add("conf.urls.url", "http://www.url4.org");

	write_xml(cout, pt);
	return 0;
}