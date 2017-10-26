WORKPATH=/home/chenhuidong/MyTools
LIBPATH=$(WORKPATH)/MyLib
INCLUDEPATH=$(WORKPATH)/MyInclude
CC=g++
CFLAGS=-ansi -Wall -w -std=c++11 -I/home/chenhuidong/MyTools/MyInclude -L/home/chenhuidong/MyTools/MyLib
CFLAGSEX=-fPIC -shared
all: install_headers libMyLog.so
install_headers:
	cp -rf include/* $(INCLUDEPATH)
libMyLog.so: MyLog.o
	$(CC) -o src/MyLog/libMyLog.so src/MyLog/MyLog.o -llog4cpp -lpthread
MyLog.o: src/MyLog/MyLog.cpp
	$(CC) -c src/MyLog/MyLog.cpp -o src/MyLog/MyLog.o $(CFLAGS) -fPIC -shared
.PHONY:clean
clean:
	rm -rf src/MyLog/libMyLog.so