#include <iostream>   
using namespace std;  
   
int main (int argc, char* argv[])  
{
	cout << "Content-type:text/html\r\n\r\n";  
	cout << "<html>\n";  
	cout << "<head>\n"; 
	cout << "<br>"; 
	cout << "<title>Wizard Linux</title>\n";  
	cout << "</head>\n";  
	cout << "<body>\n";
	cout << "<h1>Wizard Linux.</h1>\n";
	cout << "<form action=\"signupback.cgi\" method=\"get\">\n";
	cout << "username: <input type=\"text\" name=\"username\"><br>\n";
	cout << "password: <input type=\"password\" name=\"password\"><br>\n";
	cout << "<input type=\"submit\" value=\"sign up\">\n";
	cout << "</form>\n";
	cout << "</body>\n";  
	cout << "</html>\n";  
	return 0;  
}