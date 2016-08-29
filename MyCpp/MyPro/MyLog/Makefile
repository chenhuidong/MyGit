include ../Makefile.defines.linux
TARGET=libMyLog.so
OBJ=MyLog.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS)
$(OBJ): MyLog.cpp MyLog.h
	$(COMPILE) MyLog.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)