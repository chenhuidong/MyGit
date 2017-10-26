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


namespace MMyLib
{
	lua_State *g_pLua;

	#define LUAINIT(in_sFileName) {\
		g_pLua = luaL_newstate();\
		luaopen_base(g_pLua);\
		luaL_dofile(g_pLua, in_sFileName);}
};

#endif