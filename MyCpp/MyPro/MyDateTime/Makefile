include ../Makefile.defines.linux
TARGET=libMyDateTime.so
OBJ=MyDateTime.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS)
$(OBJ): MyDateTime.cpp MyDateTime.h
	$(COMPILE) MyDateTime.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)