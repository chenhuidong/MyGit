#ifndef __WIZARD_CHECK_USER_H_
#define __WIZARD_CHECK_USER_H_

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Poco/MD5Engine.h"
#include "MyDb.h"
#include "Users.h"    
using namespace std;
using Poco::MD5Engine;

class UserCheck
{
public:
	int InitializeDb();
	int UninitializeDb();

	int UserInputCheck(char* out_sUsername, char* out_sPassword);
	int SpecialWordCheck(char* in_s);
	int ExistUsername(char* in_sUsername);
	int ExistUsernamePassword(char* in_sUsername, char* in_sPassword);
	int InsertUsers(char* in_sUsername, char* in_sPassword);
private:
	MMyLib::MyDb m_oMyDb;
	Users m_oUsers;
	MD5Engine m_oMd5;
};

#endif