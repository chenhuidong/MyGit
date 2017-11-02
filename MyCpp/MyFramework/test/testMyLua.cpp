#include "MyLua.h"
#include "./Test.h"
#include "MyLog.h"
using namespace MMyLib;

int  tolua_Test_open (lua_State* tolua_S);

int main(int argc, char**argv)
{
	std::string initFileName = "MyLog.properties";

    InitLog(initFileName.c_str());
    
    //lua_State *L = luaL_newstate(); 
    //luaopen_base(g_pLua); 
    
    /*载入Lua基本库*/  
  	//luaL_openlibs(g_pLua);
  	//luaL_dofile(g_pLua, "testLua.lua");
    LUAINIT("testLua.lua");

    tolua_Test_open(g_pLua);

    int a = 1, b=2;
    lua_getglobal(g_pLua,"sum");
    lua_pushinteger(g_pLua,a);
    lua_pushinteger(g_pLua,b);
    int t_iReturn = lua_pcall(g_pLua,2,1,0);
    if (t_iReturn)				// 调用出错  
    {  
        const char *pErrorMsg = lua_tostring(g_pLua, -1);  
        cout<< pErrorMsg<< endl;  
        lua_close(g_pLua);
        return -1;  
    }

    if(lua_isnumber(g_pLua, -1))		//取值输出  
    {  
        double fValue = lua_tonumber(g_pLua, -1);  
        cout << "Result is " << fValue << endl;  
    } 

    a = 6, b=2;
    lua_getglobal(g_pLua,"minus");
    lua_pushinteger(g_pLua,a);
    lua_pushinteger(g_pLua,b);
    t_iReturn = lua_pcall(g_pLua,2,1,0);
    if (t_iReturn)				// 调用出错  
    {  
        const char *pErrorMsg = lua_tostring(g_pLua, -1);  
        cout<< pErrorMsg<< endl;  
        lua_close(g_pLua);
        return -1;  
    }

    if(lua_isnumber(g_pLua, -1))		//取值输出  
    {  
        double fValue = lua_tonumber(g_pLua, -1);  
        cout << "Result is " << fValue << endl;  
    }

    int m = 6;
    string c= "abc";
    lua_getglobal(g_pLua,"testclass");
    lua_pushinteger(g_pLua,a);
    lua_pushstring(g_pLua,c.c_str());
    t_iReturn = lua_pcall(g_pLua,2,1,0);
    if (t_iReturn)				// 调用出错  
    {  
        const char *pErrorMsg = lua_tostring(g_pLua, -1);  
        cout<< pErrorMsg<< endl;  
        lua_close(g_pLua);
        return -1;  
    }

    /*
    if(lua_isnumber(g_pLua, -1))		//取值输出  
    {  
        double fValue = lua_tonumber(g_pLua, -1);  
        cout << "Result is " << fValue << endl;  
    }
    */

    lua_close(g_pLua); 

    UninitLog();
	return 0;
}