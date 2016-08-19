main:
	g++ -omain main.cpp Test.cpp TestLua.cpp -ltolua++ -lMyLog -llua
lua:
	tolua++ -o TestLua.cpp Test.pkg
.PHONY:clean
clean:
	rm main