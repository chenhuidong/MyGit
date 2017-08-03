#ifndef __MESSI_CHECK_USER_H_
#define __MESSI_CHECK_USER_H_

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "MyDb.h"
#include "Users.h"    
using namespace std;

class UserCheck
{
public:
	int InitializeDb();
	int UninitializeDb();

	int ExistUsername(char* in_sUsername);
	int ExistUsernamePassword(char* in_sUsername, char* in_sPassword);
	int InsertUsers(char* in_sUsername, char* in_sPassword);
private:
	MMyLib::MyDb m_oMyDb;
	Users m_oUsers;
};

#endif