CC=gcc
CFLAGS= -O -Wall -pedantic -std=c11
#CFLAGS=-ggdb -Wall -pedantic -std=c11

qsolve: qsolve.o quadFuncts.o

quadFuncts: quadFuncts.h

clean: 
	rm -f *.o core qsolve
