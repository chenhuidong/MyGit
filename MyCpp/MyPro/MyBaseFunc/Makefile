include ../Makefile.defines.linux
TARGET=libMyBaseFunc.so
OBJ=MyBaseFunc.o

$(TARGET):$(OBJ)
	$(LINK) -o $(TARGET) $(OBJ) $(LDFLAGS)
$(OBJ): MyBaseFunc.cpp MyBaseFunc.h
	$(COMPILE) MyBaseFunc.cpp
testMyBaseFunc:
	make -f Makefile.testmyconf
.PHONY:clean
clean:
	rm $(TARGET) $(OBJ)