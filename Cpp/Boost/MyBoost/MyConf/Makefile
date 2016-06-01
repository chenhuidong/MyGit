include ../Makefile.defines.linux
TARGET=libMyConf.so
OBJ=MyConf.o

$(TARGET):$(OBJ)
	$(LINKSO) -o $(TARGET) $(OBJ) 
MyConf.o: MyConf.cpp MyConf.h
	$(COMPILE) MyConf.cpp
testMyConf:
	make -f Makefile.testmyconf
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)