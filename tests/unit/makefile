test_qsGetLine: test_qsGetLine.c
	gcc -o test_qsGetLine test_qsGetLine.c ../../src/quadFuncts.c  -lcunit -lm
	
test_qsResults: test_qsResults.c
	gcc -o test_qsResults test_qsResults.c ../../src/quadFuncts.c  -lcunit -lm	
	
test_qsSolve: test_qsSolve.c
	gcc -o test_qsSolve test_qsSolve.c ../../src/quadFuncts.c  -lcunit -lm
	
test_qsValidate: test_qsValidate.c
	gcc -o test_qsGetLine test_qsGetLine.c ../../src/quadFuncts.c  -lcunit -lm	
	
	
	
runAllUnitTests: test_qsGetLine test_qsResults test_qsSolve
	rm -f CUnit*.xml
	./test_qsGetLine
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-test_qsGetLine.xml
	./test_qsResults
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-test_qsResults.xml
	./test_qsSolve
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-test_qsSolve.xml
	#../tests/unit/test_qsValidate.c
	#mv CUnitAutomated-Results.xml CUnitAutomated-Results-test_qsValidate.xml