include ../Makefile.defines.linux
TARGET=libMySharedLibrary.so
OBJ=MySharedLibrary.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
$(OBJ): MySharedLibrary.cpp MySharedLibrary.h
	$(COMPILE) MySharedLibrary.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)