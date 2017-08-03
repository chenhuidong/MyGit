#ifndef __WIZARD_USER_H_
#define __WIZARD_USER_H_

#include "Poco/Tuple.h"
#include <vector>

typedef Poco::Tuple<int, std::string, std::string, std::string> User;
typedef std::vector<User> Users;

#endif