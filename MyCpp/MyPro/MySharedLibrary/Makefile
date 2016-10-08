include ../Makefile.defines.linux
TARGET=libMySharedLibrary.so
OBJ=MySharedLibrary.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS)
$(OBJ): MySharedLibrary.cpp MySharedLibrary.h ../MyException/MyException.cpp
	$(COMPILE) MySharedLibrary.cpp ../MyException/MyException.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)