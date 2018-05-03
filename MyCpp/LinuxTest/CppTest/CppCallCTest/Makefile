CppCaller: CppCaller.o CCalled.o
	g++ CppCaller.o CCalled.o -oCppCaller
CppCaller.o:
	g++ -c CppCaller.cpp 
CCalled.o:
	gcc -c CCalled.c
CCalled:
	gcc CCalled.c -oCCalled
clean:
	rm CCalled CppCaller *.o