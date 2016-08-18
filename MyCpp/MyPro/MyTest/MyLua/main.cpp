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

int  tolua_Test_open (lua_State* tolua_S);

int main(int argc, char**argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
    lua_State *L = luaL_newstate(); 
    luaopen_base(L); 
    tolua_Test_open(L);
    luaL_dofile(L, "test.lua"); 
    lua_close(L); 
	return 0;
}