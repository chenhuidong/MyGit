#include "MySharedLibrary.h"
using namespace MMyLib;

int main(int argc, char** argv)
{
	std::string initFileName = "MyLog.properties";
    InitLog(initFileName.c_str());
	IMySharedLibrary t_oProvider("/home/chenhuidong/MyProgram/MyGithub/MyGit/MyCpp/MyPro2/test/libMySharedLibraryProvider");
	t_oProvider.ExecFunc("hellokitty");
	AbstractPlugin* t_pPluginA = t_oProvider.CreateClass("PluginA");
	t_pPluginA->HelloWorld();
	delete t_pPluginA;	
	return 0;
}