#include "MySharedLibrary.h"

int main(int argc, char** argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
	MMyLib::IMySharedLibrary t_oProvider("/home/chenhuidong/MyProgram/MyGit/MyCpp/MyPro/MySharedLibrary/libMySharedLibraryProvider");
	t_oProvider.ExecFunc("hello");
	AbstractPlugin* t_pPluginA = t_oProvider.CreateClass("PluginA");
	t_pPluginA->HelloWorld();
	delete t_pPluginA;	
	return 0;
}