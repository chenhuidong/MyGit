#include <stdio.h>

extern "C"
{
  #include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
}

#include <string>
using namespace std;

int add(lua_State* L)
{
  int a = lua_tointeger(L,1);//取得函数参数
  int b = lua_tointeger(L,2);

  lua_pushinteger(L,a+b);//入栈返回值
  return 1;//1表示压入栈数据个数
}
struct luaL_Reg luaCppReg[] =//可以使用该结构体一次注册多个函数,则需要调用luaL_register函数，此处没有使用
{
  {"add",add},
  {NULL,NULL}
};
int main(int argc, char* argv[])
{
  char buff[256];
  int error;
  lua_State *L = luaL_newstate();  /* opens Lua,由于我使用的是lua5.2版本,lua_open函数不存在了 */
  luaL_openlibs(L);
  //luaopen_base(L);         /* opens the basic library 这些是在引入一些库,就如如果add函数在编译成dll后如果在lua中要使用需要require “动态库名"一样*/
  //luaopen_table(L);        /* opens the table library这些库是加在这里只是测试 */
  //luaopen_io(L);           /* opens the I/O library */
  //luaopen_string(L);       /* opens the string lib. */
  //luaopen_math(L);         /* opens the math lib. */

  
  lua_register(L,"add",add);//注册add函数,好像还可以使用luaL_register函数注册，该函数使用结构体的方式

  luaL_dofile(L,"test.lua");//加载lua文件，回将里面的函数加载到全局表中
  lua_getglobal(L,"lua_add");//查找lua_add函数,并压入栈底
  lua_pushinteger(L,6);//函数参数1
  lua_pushinteger(L,5);//函数参数2
  lua_pcall(L,2,1,0);//调用lua_add函数，同时会对lua_add及两个参加进行出栈操作,并压入返回值
  int result = lua_tointeger(L,-1);//从栈中取回返回值
  lua_pop(L,1);//清栈，由于当前只有一个返回值
  printf("result = %d\n",result);

  lua_close(L);//关闭lua环境
  return 0;
}
