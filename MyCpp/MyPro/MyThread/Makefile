include ../Makefile.defines.linux
TARGET=libMyThread.so
OBJ=MyThread.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS) 
$(OBJ): MyThread.cpp MyThread.h
	$(COMPILE) MyThread.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)