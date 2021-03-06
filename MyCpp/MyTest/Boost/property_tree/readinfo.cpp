#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/typeof/typeof.hpp> 
#include <iostream>
using namespace std;
using namespace boost::property_tree;

int main()
{
	ptree pt;
	read_info("conf.info", pt);

	cout<< pt.get<string>("conf.theme")<< endl;
	cout<< pt.get<int>("conf.clock_style")<< endl;
	cout<< pt.get<long>("conf.gui")<< endl;
	cout<< pt.get("conf.no_prop", 100)<< endl;

	BOOST_AUTO(child, pt.get_child("conf.urls"));
	for(BOOST_AUTO(pos, child.begin()); pos!= child.end(); ++pos)
	{
		cout<< pos->second.data()<< ",";
	}
	cout<< endl;
	return 0;
}