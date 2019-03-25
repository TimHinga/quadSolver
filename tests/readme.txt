tests folder

contains all of the testing performed on this program.

if you don't have CUnit installed, in command prompt type:
$: sudo apt-get update
$: sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev


testQuadSolver.c: to compile this, navigate to unit folder and type this command:
$: gcc -o testQuadSolver testQuadSolver.c ../../src/quadFuncts.c  -lcunit -lm

and then type ./testQuadSolver


