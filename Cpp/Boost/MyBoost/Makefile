TEMPALTES = Makefile.myconf
all:
	for i in `echo $(TEMPALTES)`; do\
		(make -f $i) || exit 1;\
	done
testMyConf:
	make -f Makefile.myconf
clean:
	for i in `echo $(TEMPALTES)`; do\
		(make -f $i clean) || exit 1;\
	done