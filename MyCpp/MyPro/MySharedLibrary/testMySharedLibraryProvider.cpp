#include "testMySharedLibraryProvider.h"

AbstractPlugin::AbstractPlugin()
{}

AbstractPlugin::~AbstractPlugin()
{}


PluginA::PluginA()
{}

PluginA::~PluginA()
{}

void PluginA::HelloWorld()
{
	LOG_INFO<< "hello, world!"<< std::endl;
}

POCO_BEGIN_MANIFEST(AbstractPlugin)
POCO_EXPORT_CLASS(PluginA)
POCO_END_MANIFEST

void pocoInitializeLibrary()
{
	LOG_INFO<< "PluginLibrary initializing"<< std::endl;
}

void pocoUninitializeLibrary()
{
	LOG_INFO<< "PluginLibrary uninitializing"<< std::endl;
}
