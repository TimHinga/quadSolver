.DEFAULT_GOAL := compile

cc = gcc
CFLAGS = -Wall -pedantic -std="gnu99"

compile: main.o qsGetLine.o qsSolve.o qsValidate.o answerChecker.o
	$(cc) $(CFLAGS) main.o qsGetLine.o qsSolve.o qsValidate.o answerChecker.o -o quadSolver -lm

debug: main.o qsGetLine.o qsSolve.o qsValidate.o answerChecker.o
	$(cc) $(CFLAGS) -g main.o inputReader.o quadSolver.o inputValidation.o answerChecker.o -o quadSolver -lm

main.o: main.c qsGetLine.h qsSolve.h qsValidate.h answerChecker.h
	$(cc) $(CFLAGS) -g -c main.c -o main.o
qsGetLine.o: qsGetLine.c 
	$(cc) $(CFLAGS) -g -c qsGetLine.c -o qsGetLine.o
qsSolve.o: qsSolve.c
	$(cc) $(CFLAGS) -lm -c qsSolve.c -o qsSolve.o
qsValidate.o: qsValidate.c
	$(cc) $(CFLAGS) -g -c qsValidate.c -o qsValidate.o
answerChecker.o: answerChecker.c
	$(cc) $(CFLAGS) -g -c answerChecker.c -o answerChecker.o



test_qsGetLine.o: tests/test_qsGetLine.c
	$(cc) $(CFLAGS) -c tests/test_qsGetLine.c -o test_qsGetLine.o -lcunit

test_answerChecker.o: tests/test_answerChecker.c tests/test_answerChecker.h
	$(cc) $(CFLAGS) -c tests/test_answerChecker.c -o test_answerChecker.o -lcunit

test_qsValidate.o: tests/test_qsValidate.c
	$(cc) $(CFLAGS)  -c tests/test_qsValidate.c -o test_qsValidate.o


test_qsSolve.o: tests/test_qsSolve.c tests/test_qsSolve.h
	$(cc) $(CFLAGS)  -c tests/test_qsSolve.c -o test_qsSolve.o -lcunit -lm
	
	

test_qsGetLine: test_qsGetLine.o qsGetLine.o
	$(cc) $(CFLAGS)  qsGetLine.o test_qsGetLine.o -o test_qsGetLine -lcunit

test_answerChecker: test_answerChecker.o answerChecker.o
	$(cc) $(CFLAGS) answerChecker.o test_answerChecker.o -o test_answerChecker -lcunit

test_qsValidate: qsValidate.o test_qsValidate.o
	$(cc) $(CFLAGS) qsValidate.o test_qsValidate.o -o test_qsValidate -lcunit

test_qsSolve: test_qsSolve.o qsSolve.o answerChecker.o
	$(cc) $(CFLAGS) qsSolve.o answerChecker.o test_qsSolve.o -o test_qsSolve -lcunit -lm
	

functionalTest: main.o qsGetLine.o qsSolve.o qsValidate.o answerChecker.o
	$(cc) $(CFLAGS) main.o qsGetLine.o qsSolve.o qsValidate.o answerChecker.o -o quadSolver -lm
	./quadSolver <tests/functionalTestIn.txt >tests/functionalTestActual.txt
	diff tests/functionalTestActual.txt tests/functionalTestExpected.txt


runAllUnitTests: test_qsGetLine test_qsValidate test_qsSolve test_answerChecker
	rm -f CUnit*.xml
	./test_qsGetLine
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-inputReader.xml
	./test_qsValidate
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-inputValidation.xml
	./test_qsSolve
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-quadSolver.xml
	./test_answerChecker
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-answerChecker.xml
clean:
	rm -f *.o quadSolver *Test tests/functionalTestActual.txt CUnit*.xml
