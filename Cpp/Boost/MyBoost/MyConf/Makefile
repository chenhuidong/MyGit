include ../Makefile
 
TARGET=libMyConf.so
OBJ=MyConf.o

$(TARGET): $(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
MyConf.o: MyConf.cpp MyConf.h
	$(COMPILE) MyConf.cpp
.PHONY:clean
clean:
	rm testMyConf $(OBJ)