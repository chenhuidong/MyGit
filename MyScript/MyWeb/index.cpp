#include <iostream>   
using namespace std;  
   
int main ()  
{  
      
   cout << "Content-type:text/html\r\n\r\n";  
   cout << "<html>\n";  
   cout << "<head>\n"; 
   cout << "<br>"; 
   cout << "<title>MessiLinux</title>\n";  
   cout << "</head>\n";  
   cout << "<body>\n";
   cout << "<h1>MessiLinux.</h1><br>\n";
   cout << "<p>Welcome, here is a free linux for you.</p>\n";
   cout << "<p>list of installed software:\n";
   cout << "   boost_1_61_0\n";
   cout << "   poco\n";
   cout << "   mysql\n";
   cout << "   phpmyadmin\n";
   cout << "   redis\n";
   cout << "   hiredis\n";
   cout << "   redis3m\n";
   cout << "   lua\n";
   cout << "   toluapp\n";
   cout << "   glog\n";
   cout << "   protobuf\n";
   cout << "   grpc\n";
   cout << "   libevent\n";
   cout << "   zeromq\n";
   cout << "   thrift\n";
   cout << "</p>\n";
   cout << "</body>\n";  
   cout << "</html>\n";   
   return 0;  
}