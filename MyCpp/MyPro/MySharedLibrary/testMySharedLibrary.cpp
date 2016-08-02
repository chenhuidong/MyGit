#include "MySharedLibrary.h"

int main(int argc, char** argv)
{
	MMyLib::IMySharedLibrary m_oProvider(argv[1]);
    //m_oProvider.ExecFunc("hello");
    //m_oProvider.ExecClassFunc("PluginA", "HelloWorld");
    return 0;
}