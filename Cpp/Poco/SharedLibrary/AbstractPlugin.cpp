// AbstractPlugin.cpp
//
// This is used both by the class library and by the application.
#include "AbstractPlugin.h"
AbstractPlugin::AbstractPlugin()
{}
AbstractPlugin::~AbstractPlugin()
{}


// PluginLibrary.cpp
#include "AbstractPlugin.h"
#include "Poco/ClassLibrary.h"
#include <iostream>
class PluginA: public AbstractPlugin
{
public:
		std::string name() const
		{
			return "PluginA";
		}
};
class PluginB: public AbstractPlugin
{
public:
		std::string name() const
		{
			return "PluginB";
		}
};

POCO_BEGIN_MANIFEST(AbstractPlugin)
POCO_EXPORT_CLASS(PluginA)
POCO_EXPORT_CLASS(PluginB)
POCO_END_MANIFEST

// optional set up and clean up functions
void pocoInitializeLibrary()
{
		std::cout << "PluginLibrary initializing" << std::endl;
}
void pocoUninitializeLibrary()
{
		std::cout << "PluginLibrary uninitializing" << std::endl;
}

//g++ AbstractPlugin.cpp -fPIC -shared -o libAbstractPlugin.so