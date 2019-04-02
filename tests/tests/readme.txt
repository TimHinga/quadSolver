tests folder

contains all of the testing performed on this program.

if you don't have CUnit installed, in command prompt type:
$: sudo apt-get update
$: sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev


testQuadSolver.c: to compile this, navigate to unit folder and type this command:
$: gcc -o testQuadSolver testQuadSolver.c ../../src/quadFuncts.c  -lcunit -lm

and then type ./testQuadSolver

In the tests/full folder, I have added sample input for testing and then an answer key for what the output produces with those inputs.
I have also completed the unit testing for the quad solver function, but I am stuck on the user input and input validation unit tests, as I am pretty lost on how to get through that. You can use the quad solver unit test file for reference on how I did that. 
Or, if you want, you can change it completely if it makes it easier.
Right now it is set up so that after the test runs, an XML file is generated which tells you information about that test.
