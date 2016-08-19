/*
** Lua binding: Test
** Generated automatically by tolua++-1.0.93-lua53 on Fri Aug 19 08:22:32 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "Test.h"

/* Exported function */
TOLUA_API int  tolua_Test_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CTest (lua_State* tolua_S)
{
 CTest* self = (CTest*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CTest");
}

/* method: new of class  CTest */
#ifndef TOLUA_DISABLE_tolua_Test_CTest_new00
static int tolua_Test_CTest_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CTest* tolua_ret = (CTest*)  Mtolua_new((CTest)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CTest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CTest */
#ifndef TOLUA_DISABLE_tolua_Test_CTest_new00_local
static int tolua_Test_CTest_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CTest* tolua_ret = (CTest*)  Mtolua_new((CTest)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CTest");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CTest */
#ifndef TOLUA_DISABLE_tolua_Test_CTest_delete00
static int tolua_Test_CTest_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CTest* self = (CTest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetA of class  CTest */
#ifndef TOLUA_DISABLE_tolua_Test_CTest_SetA00
static int tolua_Test_CTest_SetA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CTest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CTest* self = (CTest*)  tolua_tousertype(tolua_S,1,0);
  int _a = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetA'", NULL);
#endif
  {
   self->SetA(_a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetA of class  CTest */
#ifndef TOLUA_DISABLE_tolua_Test_CTest_GetA00
static int tolua_Test_CTest_GetA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CTest* self = (CTest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetA'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetA();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetB of class  CTest */
#ifndef TOLUA_DISABLE_tolua_Test_CTest_SetB00
static int tolua_Test_CTest_SetB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CTest",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CTest* self = (CTest*)  tolua_tousertype(tolua_S,1,0);
  std::string _b = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetB'", NULL);
#endif
  {
   self->SetB(_b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetB of class  CTest */
#ifndef TOLUA_DISABLE_tolua_Test_CTest_GetB00
static int tolua_Test_CTest_GetB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CTest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CTest* self = (CTest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetB'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetB();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Test_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CTest","CTest","",tolua_collect_CTest);
  #else
  tolua_cclass(tolua_S,"CTest","CTest","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CTest");
   tolua_function(tolua_S,"new",tolua_Test_CTest_new00);
   tolua_function(tolua_S,"new_local",tolua_Test_CTest_new00_local);
   tolua_function(tolua_S,".call",tolua_Test_CTest_new00_local);
   tolua_function(tolua_S,"delete",tolua_Test_CTest_delete00);
   tolua_function(tolua_S,"SetA",tolua_Test_CTest_SetA00);
   tolua_function(tolua_S,"GetA",tolua_Test_CTest_GetA00);
   tolua_function(tolua_S,"SetB",tolua_Test_CTest_SetB00);
   tolua_function(tolua_S,"GetB",tolua_Test_CTest_GetB00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Test (lua_State* tolua_S) {
 return tolua_Test_open(tolua_S);
};
#endif

