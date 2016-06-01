#ifndef __MY_LIB_MY_CONF_H_
#define __MY_LIB_MY_CONF_H_

#include <iostream>
#include <string> 
#include <boost/property_tree/ptree.hpp>
#include <boost/typeof/typeof.hpp> 
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace std;
using namespace boost::property_tree;

namespace MMyLib
{
	class IMyConf
	{
	public:
		enum ConfType{XML, JSON, INFO};
		IMyConf(){}
		virtual ~IMyConf(){}
		ptree& ReadFile(ConfType in_eConfType, string in_sFileName);
	private:
		ptree m_oPt;
	};
};

#endif
