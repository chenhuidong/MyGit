CC=g++
COMPILE=$(CC) $(CFLAGS) -c
LINK=$(CC) $(CFLAGS) $(LDDIR) $(LDFLAGS)
CFLAGS=-ansi -Wall -fPIC -shared
TARGET=libMyConf.so
OBJ=MyConf.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
MyConf.o: MyConf.cpp MyConf.h
	$(COMPILE) MyConf.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)