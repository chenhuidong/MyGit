#ifndef __MY_LIB_MY_ENUM_H_
#define __MY_LIB_MY_ENUM_H_

#define MYSIZE 4096
#define SERVIP "127.0.0.1"
#define SERVPORT 54321
#define CLTIP "127.0.0.1"
#define CLTPORT 54321
#define REDISIP "127.0.0.1"
#define REDISPORT 6379

enum 
{
	SDL_FAILED = -1,
	SDL_OK = 0,
	SDL_ONCE = 1;
};

#endif
