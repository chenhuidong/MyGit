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
	std::cout << "hello, world!" << std::endl;
}

POCO_BEGIN_MANIFEST(AbstractPlugin)
POCO_EXPORT_CLASS(PluginA)
POCO_END_MANIFEST

void pocoInitializeLibrary()
{
	std::cout << "PluginLibrary initializing" << std::endl;
}

void pocoUninitializeLibrary()
{
	std::cout << "PluginLibrary uninitializing" << std::endl;
}