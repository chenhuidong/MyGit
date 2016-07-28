include ../Makefile.defines.linux
TARGET=libMyException.so
OBJ=MyException.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
$(OBJ): MyException.cpp MyException.h
	$(COMPILE) MyException.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)