main: index.cgi signup.cgi signupback.cgi
testMyDb:
	g++ MyDb.cpp MyException.cpp testMyDb.cpp -otestMyDb -lglog -lPocoFoundation -lPocoData -lPocoDataSQLite -lPocoDataMySQL 
index.cgi: index.cpp
	g++ index.cpp -oindex.cgi
signup.cgi: signup.cpp
	g++ signup.cpp -osignup.cgi
signupback.cgi: MyDb.cpp MyException.cpp signupback.cpp 
	g++ MyDb.cpp MyException.cpp signupback.cpp -osignupback.cgi -lglog -lPocoFoundation -lPocoData -lPocoDataSQLite -lPocoDataMySQL 
.PHONY:clean
clean:
	rm index.cgi signup.cgi signupback.cgi