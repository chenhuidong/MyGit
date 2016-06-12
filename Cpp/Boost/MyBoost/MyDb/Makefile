include ../Makefile.defines.linux
TARGET=libMyDb.so
OBJ=MyDb.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
$(OBJ): MyDb.cpp MyDb.h
	$(COMPILE) MyDb.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)