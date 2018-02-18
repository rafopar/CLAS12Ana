CC              = g++ -std=c++11
CC_OBJ_FLAGS    = -c -fPIC
CC_Shared_FLAGS = -shared -Wl,-soname,libTrigDiag.so
ROOT_CFLAGS     = $(shell /usr/local/apps/root/6_12_06/bin/root-config --cflags)
ROOT_LIBS       = $(shell /usr/local/apps/root/6_12_06/bin/root-config --libs)
CODA            = /Work/apps/coda
CODA_FLAGS      = -I${CODA}/Linux-x86_64/include
HLS_FLAGS       = -I/Work/apps/Vivado_HLS/2015.4/include
libCLAS12ana    = libCLAS12ana


all:		TAnaDB.o
		rm -f ${libCLAS12ana}.so*
		$(CC) $(CC_Shared_FLAGS) -o lib/${libCLAS12ana}.so.1.0.1 $?
		cd lib;\
		ln -sf ${libCLAS12ana}.so.1.0.1 ${libCLAS12ana}.so.1; ln -sf ${libCLAS12ana}.so.1.0.1 ${libCLAS12ana}.so
	
TAnaDB.o:	src/TAnaDB.cxx include/TAnaDB.hh
		$(CC) $(CC_OBJ_FLAGS) src/TAnaDB.cxx -o $@ $(ROOT_CFLAGS) -I./include

clean:
		rm -f lib/*.so.* lib/*.so *.o
