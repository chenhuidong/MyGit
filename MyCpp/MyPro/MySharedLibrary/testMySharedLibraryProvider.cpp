#include "testMySharedLibraryProvider.h"

int hellokitty()
{
    LOG_INFO<< "hello kitty!" << std::endl;
    return SDL_ONCE;
}

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
	//LOG_INFO<< "hello, world!"<< std::endl;
	MyLog::pLog.info("hello, world!\n");
}

POCO_BEGIN_MANIFEST(AbstractPlugin)
POCO_EXPORT_CLASS(PluginA)
POCO_END_MANIFEST

void pocoInitializeLibrary()
{
	//LOG_INFO<< "PluginLibrary initializing."<< std::endl;
	MyLog::pLog.info("PluginLibrary initializing.\n");
}

void pocoUninitializeLibrary()
{
	//LOG_INFO<< "PluginLibrary uninitializing."<< std::endl;
	MyLog::pLog.info("PluginLibrary uninitializing.\n");
}
