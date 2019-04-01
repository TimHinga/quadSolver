cc = gcc
CFLAGS = -Wall -pedantic -std=c11 -lm

functionalTest: ../../src/qsolve.o ../../src/quadFuncts.o
	$(cc) $(CFLAGS) ../../src/qsolve.o ../../src/quadFuncts.o -o qsolve -lm
	../../src/qsolve < functionalTestIn.txt > functionalTestActual.txt
	diff functionalTestActual.txt functionalTestExpected.txt
