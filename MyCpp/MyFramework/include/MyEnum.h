#ifndef __MY_LIB_MY_ENUM_H_
#define __MY_LIB_MY_ENUM_H_

#define MYSIZE 4096
#define SERVIP "127.0.0.1"
#define SERVPORT 54321
#define CLTIP "127.0.0.1"
#define CLTPORT 54321
#define REDISIP "172.17.138.176"
#define REDISPORT 7000

typedef long long int64;
typedef int int32;
typedef short int16;

enum 
{
	SDL_FAILED = -1,
	SDL_OK = 0,
	SDL_ONCE = 1,
};

#endif
