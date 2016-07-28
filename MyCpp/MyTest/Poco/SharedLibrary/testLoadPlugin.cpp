// main.cpp
#include "Poco/ClassLoader.h"
#include "Poco/Manifest.h"
#include "AbstractPlugin.h"
#include <iostream>
typedef Poco::ClassLoader<AbstractPlugin> PluginLoader;
typedef Poco::Manifest<AbstractPlugin> PluginManifest;
int main(int argc, char** argv)
{
		PluginLoader loader;
		std::string libName("libAbstractPlugin");
		libName += Poco::SharedLibrary::suffix(); // append .dll or .so
		loader.loadLibrary(libName);
		PluginLoader::Iterator it(loader.begin());
		PluginLoader::Iterator end(loader.end());
		for (; it != end; ++it)
		{
			std::cout << "lib path: " << it->first << std::endl;
			PluginManifest::Iterator itMan(it->second->begin());
			PluginManifest::Iterator endMan(it->second->end());
			for (; itMan != endMan; ++itMan)
			std::cout << itMan->name() << std::endl;
		}
		AbstractPlugin* pPluginA = loader.create("PluginA");
		AbstractPlugin* pPluginB = loader.create("PluginB");
		std::cout << pPluginA->name() << std::endl;
		std::cout << pPluginB->name() << std::endl;
		loader.classFor("PluginA").autoDelete(pPluginA);
		delete pPluginB;
		loader.unloadLibrary(libName);
		return 0;
}