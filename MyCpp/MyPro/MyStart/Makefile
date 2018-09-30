include ../Makefile.defines.linux
OBJ=MyStart.o 

MyStart: $(OBJ)
	$(LINKEXE) -o MyStart $(OBJ) $(LDFLAGS) $(LDFLAGSEX)
$(OBJ):  
	$(COMPILE) MyStart.cpp
.PHONY:clean
clean:
	rm MyStart $(OBJ)