include Makefile.defines.linux

SUBDIRS = MyException MyLog MyBaseFunc MyConf MyDateTime MyThread MyDb MyRedis MyNet MyTR MySharedLibrary MyLua
all:
	mkdir -p $(LIBPATH) $(INCLUDEPATH);\
	cp -rf *.h $(INCLUDEPATH);\
	for i in $(SUBDIRS); do\
		(cd $$i && cp -rf *.h $(INCLUDEPATH)) || exit 1;\
	done;\
	for i in $(SUBDIRS); do\
		(cd $$i && make && cp *"$$i".so $(LIBPATH)) || exit 1;\
	done
install:
	mkdir -p $(LIBPATH) $(INCLUDEPATH);\
	for i in $(SUBDIRS); do\
		(cd $$i && cp *"$$i"*.so $(LIBPATH)) || exit 1;\
	done
test:
	for i in $(SUBDIRS); do\
		(cd $$i && make -f Makefile.*) || exit 1;\
	done
.PHONY:clean
clean:
	for i in $(SUBDIRS); do\
		(cd $$i && make clean ) || exit 1;\
		rm $(LIBPATH)/*"$$i"*.so;\
	done