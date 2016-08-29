include ../Makefile.defines.linux
TARGET=libMyNet.so
OBJ=MyNet.o student.pb.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS)
$(OBJ): MyNet.cpp MyNet.h student.pb.cc
	$(COMPILE) MyNet.cpp student.pb.cc
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)