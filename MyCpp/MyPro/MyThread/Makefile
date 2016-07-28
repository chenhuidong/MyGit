include ../Makefile.defines.linux
TARGET=libMyThread.so
OBJ=MyThread.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
$(OBJ): MyThread.cpp MyThread.h
	$(COMPILE) MyThread.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)