include ../Makefile.defines.linux
TARGET=libMyNet.so
OBJ=MyNet.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
$(OBJ): MyNet.cpp MyNet.h
	$(COMPILE) MyNet.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)