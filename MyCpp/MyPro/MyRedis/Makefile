include ../Makefile.defines.linux
TARGET=libMyRedis.so
OBJ=MyRedis.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
$(OBJ): MyRedis.cpp MyRedis.h
	$(COMPILE) MyRedis.cpp
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)