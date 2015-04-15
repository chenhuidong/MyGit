#include <iostream>
using namespace std;
#include <stdio.h>

#define OTL_ODBC_MSSQL_2008 // Compile OTL 4/ODBC, MS SQL 2008
//#define OTL_ODBC // Compile OTL 4/ODBC. Uncomment this when used with MS SQL 7.0/ 2000
#include <otlv4.h> // include the OTL 4 header file

otl_connect db; // connect object

void insert()
// insert rows into table
{ 
 otl_stream o(10, // buffer size
              "insert into test_tab values(:f1<int>,:f2<char[31]>)", 
                 // SQL statement
              db // connect object
             );

 o.set_commit(0); // set stream's auto-commit to OFF.

 try{
  o<<1<<"Line1"; // Enter one row into the stream
  o.flush(); // flush the strem buffer, i.e. force
             // the stream to execute
#if defined(OTL_ANSI_CPP_11_VARIADIC_TEMPLATES)
  otl_write_row(o,1,"Line1"); // Enter the same data into the stream
                              // and cause a "duplicate key" error.
#else
  // when variadic template functions are not supported by the C++
  // compiler, OTL provides nonvariadic versions of the same template
  // functions in the range of [1..15] parameters
  otl_write_row(o,1,"Line1"); // Enter the same data into the stream
  // the old way (operators >>() / <<()) is available as always:
  //  o<<1<<"Line1"; // Enter the same data into the stream
                    // and cause a "duplicate key" error.
#endif

  o.flush();
 }catch(otl_exception& p){
  if(p.code==2601){
   // ... duplicate key ...
    cout<<"STREAM ERROR STATE="<<o.get_error_state()<<endl;

    o.clean(1); // clean up the stream's buffer
               // and clean up the stream's internal
               // error flag as well. By doing this, 
               // it's possible to recover from 
               // a database error without closing
               // the stream. Remember, the number of 
               // situtation when it's possible is 
               // limited and the recover procedure should
               // be carefully designed.
  }else
   throw; // re-throw the exception to the outer catch block.
 }


 o<<2<<"Line2"; // Enter one more row of data after
                // recovering from the "duplicate key" 
                // error
 o.flush();

 db.commit(); // commit transaction

}

void select()
{ 
 otl_stream i(10, // buffer size
              "select * from test_tab",
                 // SELECT statement
              db // connect object
             ); 
   // create select stream
 
 int f1;
 char f2[31];

 while(!i.eof()){ // while not end-of-data
#if defined(OTL_ANSI_CPP_11_VARIADIC_TEMPLATES)
   otl_read_row(i,f1,f2);
#else
  // when variadic template functions are not supported by the C++
  // compiler, OTL provides nonvariadic versions of the same template
  // functions in the range of [1..15] parameters
   otl_read_row(i,f1,f2);
  // the old way (operators >>() / <<()) is available as always:
  //   i>>f1>>f2;
#endif
  cout<<"f1="<<f1<<", f2="<<f2<<endl;
 }

}

int main()
{
 otl_connect::otl_initialize(); // initialize ODBC environment
 try{

  db.rlogon("scott/tiger@mssql2008"); // connect to the database

  otl_cursor::direct_exec
   (
    db,
    "drop table test_tab",
    otl_exception::disabled // disable OTL exceptions
   ); // drop table

  otl_cursor::direct_exec
   (
    db,
    "create table test_tab(f1 int, f2 varchar(30))"
    );  // create table

  otl_cursor::direct_exec
   (
    db,
    "create unique index ind001 on test_tab(f1)"
    );  // create unique index 

  insert(); // insert records into table
  select(); // select records from table

 }

 catch(otl_exception& p){ // intercept OTL exceptions
  cerr<<p.code<<endl; // print out error code
  cerr<<p.sqlstate<<endl; // print out error SQLSTATE
  cerr<<p.msg<<endl; // print out error message
  cerr<<p.stm_text<<endl; // print out SQL that caused the error
  cerr<<p.var_info<<endl; // print out the variable that caused the error
 }

 db.logoff(); // disconnect from the database

 return 0;

}
