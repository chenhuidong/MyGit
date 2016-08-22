#ifndef __MY_LIB_MY_LUA_H_
#define __MY_LIB_MY_LUA_H_

#include "MyStdAfx.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


lua_State *L;
#define LuaInit(const char* in_sFileName)\
L = luaL_newstate();\
luaopen_base(L);\
luaL_dofile(L, in_sFileName);


#endif