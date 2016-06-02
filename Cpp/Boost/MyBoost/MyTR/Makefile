include ../Makefile.defines.linux
TARGET=libMyTR.so
OBJ=MyTR.o

$(TARGET):$(OBJ)
	$(LINKSO) -o $(TARGET) $(OBJ) 
MyTR.o: MyTR.cpp MyTR.h
	$(COMPILE) MyTR.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)