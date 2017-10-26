WORKPATH=/home/chenhuidong/MyTools
LIBPATH=$(WORKPATH)/MyLib
INCLUDEPATH=$(WORKPATH)/MyInclude
CC=g++
CFLAGS=-ansi -Wall -w -std=c++11 -I$(INCLUDEPATH) -L$(LIBPATH)
CFLAGSEX=-fPIC -shared
install_headers:
	cp -rf include/* $(INCLUDEPATH)
all: libMyLog.so
libMyLog.so: MyLog.o
	$(CC) src/MyLog/MyLog.o -o src/MyLog/libMyLog.so -llog4cpp -lpthread $(CFLAGSEX)
MyLog.o: src/MyLog/MyLog.cpp
	$(CC) -c src/MyLog/MyLog.cpp -o src/MyLog/MyLog.o $(CFLAGS) $(CFLAGSEX)
install:
	cp src/MyLog/libMyLog.so $(LIBPATH)
.PHONY:clean
clean:
	rm -rf src/MyLog/libMyLog.so src/MyLog/MyLog.o