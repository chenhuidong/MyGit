#include <iostream>
using namespace std;
#include <stdio.h>
#if !defined(ORA_VER_DEFINED)
#define OTL_ORA8I // Compile OTL 4.0/OCI8i
#endif
#define OTL_UNICODE // Enable Unicode OTL for OCI8i
#include <otlv4.h> // include the OTL 4.0 header file

otl_connect db; // connect object

void insert()
// insert rows into table
{ 
 otl_stream o(50, // buffer size
              "insert into test_tab values(:f1<float>,:f2<char[31]>)", 
                 // SQL statement
              db // connect object
             );
 char tmp[32];
 unsigned short tmp2[32]; // Null terminated Unicode character array.

 for(int i=1;i<=100;++i){
#if defined(_MSC_VER)
#if (_MSC_VER >= 1400) // VC++ 8.0 or higher
  sprintf_s(tmp,sizeof(tmp),"Name%d",i);
#else
  sprintf(tmp,"Name%d",i);
#endif
#else
  sprintf(tmp,"Name%d",i);
#endif
  unsigned short* c2=tmp2;
  char* c1=tmp;
// Unicode's first 128 characters are ASCII (0..127), so
// all is needed for converting ASCII into Unicode is as follows:
  while(*c1){
    *c2=OTL_SCAST(unsigned char,*c1);
   ++c1; ++c2;   
  }  
  *c2=0; // target Unicode string is null terminated,
         // only the null terminator is a two-byte character, 
         // not one-byte
  o<<static_cast<float>(i);
  o<<OTL_RCAST(unsigned char*,tmp2); 
   // overloaded operator<<(const unsigned char*) in the case of Unicode
   // OTL accepts a pointer to a Unicode character array.
   // operator<<(const unsigned short*) wasn't overloaded
   // in order to avoid ambiguity in C++ type casting.
 }

}

void select()
{ 
 otl_stream i(50, // buffer size
              "select * from test_tab where f1>=:f<int> and f1<=:f*2",
                 // SELECT statement
              db // connect object
             ); 
   // create select stream
 
 float f1;
 unsigned short f2[32];

 i<<8; // assigning :f = 8
   // SELECT automatically executes when all input variables are
   // assigned. First portion of output rows is fetched to the buffer

 while(!i.eof()){ // while not end-of-data
  i>>f1;
  i>>OTL_RCAST(unsigned char*,f2);
    // overloaded operator>>(unsigned char*) in the case of Unicode
    // OTL accepts a pointer to a Unicode chracter array.
    // operator>>(unsigned short*) wasn't overloaded 
    // in order to avoid ambiguity in C++ type casting.
  cout<<"f1="<<f1<<", f2=";
// Unicode's first 128 characters are ASCII, so in order
// to convert Unicode back to ASCII all is needed is
// as follows:
   for(int j=0;f2[j]!=0;++j){
     cout<<OTL_SCAST(char,f2[j]);
   }
   cout<<endl;
 }

 i<<4; // assigning :f = 4
   // SELECT automatically executes when all input variables are
   // assigned. First portion of output rows is fetched to the buffer

 while(!i.eof()){ // while not end-of-data
   i>>f1>>OTL_RCAST(unsigned char*,f2);
  cout<<"f1="<<f1<<", f2=";
   for(int j=0;f2[j]!=0;++j){
     cout<<OTL_SCAST(char,f2[j]);
   }
   cout<<endl;
 }

}

int main()
{
 otl_connect::otl_initialize(); // initialize OCI environment
 try{

  db.rlogon("system/oracle@myora_tns"); // connect to Oracle

  otl_cursor::direct_exec
   (
    db,
    "drop table test_tab",
    otl_exception::disabled // disable OTL exceptions
   ); // drop table

  otl_cursor::direct_exec
   (
    db,
    "create table test_tab(f1 number, f2 varchar2(60))"
    );  // create table

  insert(); // insert records into table
  select(); // select records from table

 }

 catch(otl_exception& p){ // intercept OTL exceptions
  cerr<<p.msg<<endl; // print out error message
  cerr<<p.stm_text<<endl; // print out SQL that caused the error
  cerr<<p.var_info<<endl; // print out the variable that caused the error
 }

 db.logoff(); // disconnect from Oracle

 return 0;

}
