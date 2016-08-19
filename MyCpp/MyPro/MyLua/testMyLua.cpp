#include "MyLua.h"
#include "Test.h"

int  tolua_Test_open (lua_State* tolua_S);

int main(int argc, char**argv)
{
	MMyLib::INITIALIZE_LOG(argv[0]);
    
    lua_State *L = luaL_newstate(); 
    luaopen_base(L); 
    
    /*载入Lua基本库*/  
  	//luaL_openlibs(L);
  	luaL_dofile(L, "testLua.lua");

    tolua_Test_open(L);

    int a = 1, b=2;
    lua_getglobal(L,"sum");
    lua_pushinteger(L,a);
    lua_pushinteger(L,b);
    int t_iReturn = lua_pcall(L,2,1,0);
    if (t_iReturn)				// 调用出错  
    {  
        const char *pErrorMsg = lua_tostring(L, -1);  
        cout<< pErrorMsg<< endl;  
        lua_close(L);
        return -1;  
    }

    if(lua_isnumber(L, -1))		//取值输出  
    {  
        double fValue = lua_tonumber(L, -1);  
        cout << "Result is " << fValue << endl;  
    } 

    a = 6, b=2;
    lua_getglobal(L,"minus");
    lua_pushinteger(L,a);
    lua_pushinteger(L,b);
    t_iReturn = lua_pcall(L,2,1,0);
    if (t_iReturn)				// 调用出错  
    {  
        const char *pErrorMsg = lua_tostring(L, -1);  
        cout<< pErrorMsg<< endl;  
        lua_close(L);
        return -1;  
    }

    if(lua_isnumber(L, -1))		//取值输出  
    {  
        double fValue = lua_tonumber(L, -1);  
        cout << "Result is " << fValue << endl;  
    }

    int m = 6;
    string c= "abc";
    lua_getglobal(L,"testclass");
    lua_pushinteger(L,a);
    lua_pushstring(L,c.c_str());
    t_iReturn = lua_pcall(L,2,1,0);
    if (t_iReturn)				// 调用出错  
    {  
        const char *pErrorMsg = lua_tostring(L, -1);  
        cout<< pErrorMsg<< endl;  
        lua_close(L);
        return -1;  
    }

    /*
    if(lua_isnumber(L, -1))		//取值输出  
    {  
        double fValue = lua_tonumber(L, -1);  
        cout << "Result is " << fValue << endl;  
    }
    */

    lua_close(L); 
	return 0;
}