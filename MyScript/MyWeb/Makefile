main: index.cgi signup.cgi signupback.cgi
testMyDb:
	g++ MyDb.cpp MyException.cpp testMyDb.cpp -otestMyDb -lglog -lPocoFoundation -lPocoData -lPocoDataSQLite -lPocoDataMySQL 
index.cgi:
	g++ index.cpp -oindex.cgi
signup.cgi:
	g++ signup.cpp -osignup.cgi
signupback.cgi:
	g++ signupback.cpp -osignupback.cgi
.PHONY:clean
clean:
	rm index.cgi signup.cgi signupback.cgi