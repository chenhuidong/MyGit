main: index.cgi signup.cgi signupback.cgi
testMyDb:
	g++ MyDb.cpp MyException.cpp testMyDb.cpp -otestMyDb -lglog -lPocoFoundation -lPocoData -lPocoDataSQLite -lPocoDataMySQL 
index.cgi: Index.cpp
	g++ Index.cpp -oindex.cgi
signup.cgi: Signup.cpp
	g++ Signup.cpp -osignup.cgi
signupback.cgi: MyDb.cpp MyException.cpp SignupBack.cpp 
	g++ MyDb.cpp MyException.cpp CheckUser.cpp SignupBack.cpp -osignupback.cgi -lglog -lPocoFoundation -lPocoData -lPocoDataSQLite -lPocoDataMySQL -lPocoFoundation
.PHONY: clean install
clean:
	rm index.cgi signup.cgi signupback.cgi
install:
	cp ./*.cgi /var/www/html/WizardLinux