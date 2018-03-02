WORKPATH=/home/chenhuidong/MyProject
LIBPATH=$(WORKPATH)/MyLib
INCLUDEPATH=$(WORKPATH)/MyInclude
COMPLIEPATH=/home/chenhuidong/MyProject/MyGit/MyCpp/MyFramework/src
CC=g++
CFLAGS=-ansi -g -Wall -w -std=c++11 -I$(INCLUDEPATH) -L$(LIBPATH) -L$(COMPLIEPATH)
CFLAGSEX=-fPIC -shared
all: install_headers libMyLog.so libMyBaseFunc.so libMyDateTime.so libMyConf.so libMyRedis.so libMyLua.so libMyException.so libMySharedLibrary.so libMyThread.so libMyDb.so libMyNet.so libMyTR.so
install_headers:
	cp -rf include/* $(INCLUDEPATH)
libMyTR.so: MyTR.o
	$(CC) src/MyTR.o -o src/libMyTR.so $(CFLAGSEX)
MyTR.o: src/MyTR.cpp
	$(CC) -c src/MyTR.cpp -o src/MyTR.o $(CFLAGS) $(CFLAGSEX)
libMyNet.so: MyNet.o
	$(CC) src/MyNet.o -o src/libMyNet.so -lboost_system -lMyLog $(CFLAGSEX)
MyNet.o: src/MyNet.cpp
	$(CC) -c src/MyNet.cpp -o src/MyNet.o $(CFLAGS) $(CFLAGSEX)
libMyDb.so: MyDb.o
	$(CC) src/MyDb.o -o src/libMyDb.so -lMyLog -lPocoData -lPocoDataSQLite -lPocoDataMySQL -lMyException $(CFLAGSEX)
MyDb.o: src/MyDb.cpp
	$(CC) -c src/MyDb.cpp -o src/MyDb.o $(CFLAGS) $(CFLAGSEX)
libMyThread.so: MyThread.o
	$(CC) src/MyThread.o -o src/libMyThread.so -lboost_thread-mt $(CFLAGSEX)
MyThread.o: src/MyThread.cpp
	$(CC) -c src/MyThread.cpp -o src/MyThread.o $(CFLAGS) $(CFLAGSEX)
libMySharedLibrary.so: MySharedLibrary.o testMySharedLibraryProvider.o
	$(CC) src/MySharedLibrary.o src/testMySharedLibraryProvider.o -o src/libMySharedLibrary.so -lMyException -lMyLog -lPocoFoundation $(CFLAGSEX)
libMySharedLibraryProvider.so: testMySharedLibraryProvider.o
	$(CC) src/testMySharedLibraryProvider.o -o test/libMySharedLibraryProvider.so -lMyLog $(CFLAGSEX)
testMySharedLibraryProvider.o: src/testMySharedLibraryProvider.cpp
	$(CC) -c src/testMySharedLibraryProvider.cpp -o src/testMySharedLibraryProvider.o $(CFLAGS) $(CFLAGSEX)
MySharedLibrary.o: src/MySharedLibrary.cpp src/testMySharedLibraryProvider.cpp
	$(CC) -c src/MySharedLibrary.cpp -o src/MySharedLibrary.o $(CFLAGS) $(CFLAGSEX)
libMyException.so: MyException.o
	$(CC) src/MyException.o -o src/libMyException.so -lPocoFoundation $(CFLAGSEX)
MyException.o: src/MyException.cpp
	$(CC) -c src/MyException.cpp -o src/MyException.o $(CFLAGS) $(CFLAGSEX)
libMyLua.so: MyLua.o
	$(CC) src/MyLua.o -o src/libMyLua.so -ltolua++ -llua $(CFLAGSEX)
MyLua.o: src/MyLua.cpp
	$(CC) -c src/MyLua.cpp -o src/MyLua.o $(CFLAGS) $(CFLAGSEX)
libMyRedis.so: MyRedis.o
	$(CC) src/MyRedis.o -o src/libMyRedis.so -lredis3m $(CFLAGSEX)
MyRedis.o: src/MyRedis.cpp
	$(CC) -c src/MyRedis.cpp -o src/MyRedis.o $(CFLAGS) $(CFLAGSEX)
libMyConf.so: MyConf.o
	$(CC) src/MyConf.o -o src/libMyConf.so $(CFLAGSEX)
MyConf.o: src/MyConf.cpp
	$(CC) -c src/MyConf.cpp -o src/MyConf.o $(CFLAGS) $(CFLAGSEX)
libMyDateTime.so: MyDateTime.o
	$(CC) src/MyDateTime.o -o src/libMyDateTime.so -lboost_date_time $(CFLAGSEX)
MyDateTime.o: src/MyDateTime.cpp
	$(CC) -c src/MyDateTime.cpp -o src/MyDateTime.o $(CFLAGS) $(CFLAGSEX)
libMyBaseFunc.so: MyBaseFunc.o
	$(CC) src/MyBaseFunc.o -o src/libMyBaseFunc.so $(CFLAGSEX)
MyBaseFunc.o: src/MyBaseFunc.cpp
	$(CC) -c src/MyBaseFunc.cpp -o src/MyBaseFunc.o $(CFLAGS) $(CFLAGSEX)
libMyLog.so: MyLog.o
	$(CC) src/MyLog.o -o src/libMyLog.so -llog4cpp -lpthread $(CFLAGSEX)
MyLog.o: src/MyLog.cpp
	$(CC) -c src/MyLog.cpp -o src/MyLog.o $(CFLAGS) $(CFLAGSEX)
test: testMyLog testMyBaseFunc testMyDateTime testMyConf testMyDb testMyLua testMyRedis testMySharedLibrary testMyThread testMyServ
testMyLog: 
	$(CC) test/testMyLog.cpp -o test/testMyLog -lMyLog -llog4cpp $(CFLAGS)
testMyBaseFunc:
	$(CC) test/testMyBaseFunc.cpp -o test/testMyBaseFunc -lMyBaseFunc $(CFLAGS)
testMyDateTime:
	$(CC) test/testMyDateTime.cpp -o test/testMyDateTime -lMyDateTime -lboost_date_time $(CFLAGS)
testMyConf:
	$(CC) test/testMyConf.cpp -o test/testMyConf -lMyConf $(CFLAGS)
testMyDb:
	$(CC) test/testMyDb.cpp -o test/testMyDb -lMyDb -lPocoFoundation -lPocoData -lMyException -lMyLog -llog4cpp $(CFLAGS)
testMyLua: Test.o TestLua.o testMyLua.o
	$(CC) -o test/testMyLua test/Test.o test/TestLua.o test/testMyLua.o -lMyLog -llog4cpp -ltolua++ -llua $(CFLAGS)
Test.o: test/Test.cpp
	$(CC) -c test/Test.cpp -o test/Test.o $(CFLAGS) 
TestLua.o: test/TestLua.cpp 
	$(CC) -c test/TestLua.cpp -o test/TestLua.o $(CFLAGS) 
testMyLua.o: test/testMyLua.cpp 
	$(CC) -c test/testMyLua.cpp -o test/testMyLua.o $(CFLAGS)
lua:
	tolua++ -o test/TestLua.cpp test/Test.pkg
testMyRedis:
	$(CC) test/testMyRedis.cpp -o test/testMyRedis -lMyRedis -lredis3m $(CFLAGS)
testMySharedLibrary: libMySharedLibraryProvider.so 
	$(CC) test/testMySharedLibrary.cpp -o test/testMySharedLibrary -lMySharedLibrary -lMyLog -llog4cpp $(CFLAGS)
testMyThread:
	$(CC) test/testMyThread.cpp -o test/testMyThread -lMyThread -lboost_system -lboost_thread-mt $(CFLAGS)
testMyServ:
	$(CC) -o testMyServ test/testMyServ.cpp test/student.pb.cc -lMyNet -lMyLog -llog4cpp -lboost_system -lprotobuf $(CFLAGS)
pb:
	protoc --cpp_out=./test  test/student.proto
install:
	cp src/lib*.so $(LIBPATH) 
.PHONY:clean
clean:
	rm -rf src/lib*.so src/*.o test/*.o 