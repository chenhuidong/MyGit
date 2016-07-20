include ../Makefile.defines.linux
TARGET=libMyNet.so
OBJ=MyNet.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) 
$(OBJ): MyNet.cpp MyNet.h student.pb.cc
	$(COMPILE) MyNet.cpp student.pb.cc
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)