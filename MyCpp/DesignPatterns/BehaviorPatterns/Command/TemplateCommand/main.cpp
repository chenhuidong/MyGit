//main.cpp
#include "Command.h"
#include "Reciever.h"
#include <iostream> 
using namespace std;

int main(int arc,char* argv[]) 
{ 
	Reciever* rev = new Reciever();
	Command* cmd = new SimpleCommand<Reciever>(rev,&Reciever::Action);
	cmd->Excute();
	return 0; 
}