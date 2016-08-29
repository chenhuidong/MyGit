include ../Makefile.defines.linux
TARGET=libMyTR.so
OBJ=MyTR.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS) 
$(OBJ): MyTR.cpp MyTR.h
	$(COMPILE) MyTR.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)