WORKPATH=/home/chenhuidong/MyTools
LIBPATH=$(WORKPATH)/MyLib
INCLUDEPATH=$(WORKPATH)/MyInclude
CC=g++
CFLAGS=-ansi -Wall -w -std=c++11 -I$(INCLUDEPATH) -L$(LIBPATH)
CFLAGSEX=-fPIC -shared
install_headers:
	cp -rf include/* $(INCLUDEPATH)
all: libMyLog.so libMyBaseFunc.so
libMyBaseFunc.so: MyBaseFunc.o
	$(CC) src/MyBaseFunc/MyBaseFunc.o -o src/MyBaseFunc/libMyBaseFunc.so $(CFLAGSEX)
MyBaseFunc.o: src/MyBaseFunc/MyBaseFunc.cpp
	$(CC) -c src/MyBaseFunc/MyBaseFunc.cpp -o src/MyBaseFunc/MyLog.o $(CFLAGS) $(CFLAGSEX)
libMyLog.so: MyLog.o
	$(CC) src/MyLog/MyLog.o -o src/MyLog/libMyLog.so -llog4cpp -lpthread $(CFLAGSEX)
MyLog.o: src/MyLog/MyLog.cpp
	$(CC) -c src/MyLog/MyLog.cpp -o src/MyLog/MyLog.o $(CFLAGS) $(CFLAGSEX)
install:
	cp src/MyLog/libMyLog.so src/MyBaseFunc/libMyBaseFunc.so $(LIBPATH)
.PHONY:clean
clean:
	rm -rf src/MyLog/libMyLog.so src/MyLog/MyLog.o src/MyBaseFunc/libMyBaseFunc.so src/MyBaseFunc/MyBaseFunc.o