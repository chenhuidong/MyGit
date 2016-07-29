#include "MySharedLibrary.h"

int main(int argc, char** argv)
{
	MMyLib::IMySharedLibrary m_oProvider("/home/chenhuidong/MyProgram/MyGit/MyCpp/MyPro/MySharedLibrary/libMySharedLibraryProvider.so");
    m_oProvider.ExecFunc("hello");
    return 0;
}