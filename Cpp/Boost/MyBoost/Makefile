include Makefile.defines.linux

SUBDIRS = MyConf
all:
	for i in $(SUBDIRS); do\
		(cd $$i && make && mv "*$$i*.so" $LIBPATH) || exit 1;\
	done
.PHONY:clean
clean:
	for i in $(SUBDIRS); do\
		(cd $$i && make clean && rm "$LIBPATH/*$$i*.so") || exit 1;\
	done