SUBDIRS = MyConf
CC=g++
COMPILE=$(CC) $(CFLAGS) -c
LINK=$(CC) $(CFLAGS) $(LDDIR) $(LDFLAGS)
CFLAGS=-ansi -Wall -fPIC -shared
#TEMPALTES = Makefile.myconf
all:
	for i in $(SUBDIRS); do\
		(cd $$i && make all) || exit 1;\
	done
.PHONY:clean
clean:
	for i in $(SUBDIRS); do\
		(cd $$i && make clean) || exit 1;\
	done