include ../Makefile.defines.linux
TARGET=libMyLua.so
OBJ=MyLua.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS)
$(OBJ): MyLua.cpp MyLua.h
	$(COMPILE) MyLua.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)