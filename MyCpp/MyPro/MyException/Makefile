include ../Makefile.defines.linux
TARGET=libMyException.so
OBJ=MyException.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS)
$(OBJ): MyException.cpp MyException.h
	$(COMPILE) MyException.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)