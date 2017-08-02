#ifndef __MESSI_USER_H_
#define __MESSI_USER_H_

#include "Poco/Tuple.h"
#include <vector>

typedef Poco::Tuple<int, std::string, std::string, std::string> User;
typedef std::vector<User> Users;

#endif