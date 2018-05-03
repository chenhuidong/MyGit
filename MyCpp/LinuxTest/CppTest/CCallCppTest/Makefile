CCaller: libAdapterP.a
	gcc CCaller.c -oCCaller libAdapterP.a -lstdc++
libAdapterP.a: CppCalled.o Adapter.o
	ar rcs libAdapterP.a Adapter.o CppCalled.o 
CppCalled.o:
	g++ -c CppCalled.cpp 
Adapter.o:
	g++ -c Adapter.cpp
clean:
	rm *.o *.a CCaller