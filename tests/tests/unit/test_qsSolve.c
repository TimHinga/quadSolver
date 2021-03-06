#include "test_qsSolve.h"


int close() {
    return 0;
}

int init(){
    return 0;
}

void quadSolverTest_basic(){
    double x1;
    double x2;
    
    int retVal;
    retVal = qsSolve(1.0,0.0,-9.0,&x1,&x2);
    CU_ASSERT(x1 <= 3.01);
    CU_ASSERT(x1 >= 2.99);
    CU_ASSERT(x2 >= -3.01);
    CU_ASSERT(x2 <= -2.99);
    CU_ASSERT(x1 != x2);
    CU_ASSERT(retVal == 1);

}

void quadSolverTest_ZeroDeterminant(){
	double x1, x2;
	int retVal = qsSolve(1.0,4.0,4.0, &x1, &x2);
	CU_ASSERT(x1 >= -2.01);
	CU_ASSERT(x1 <= -1.99);
	CU_ASSERT(retVal == 2);
	
}

void quadSolverTest_Imaginary(){
	double x1, x2;
	int retVal = qsSolve(1.0,1.0,4.0, &x1, &x2);
	CU_ASSERT(retVal == 3);
	
}


int main(int argc, char * argv[]){
	
	CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("quadSolverSuite",init,close);
    CU_add_test(psuite,"quadSolverTest_basic",quadSolverTest_basic);
    CU_add_test(psuite,"quadSolverTest_ZD",quadSolverTest_ZeroDeterminant);
    CU_add_test(psuite,"quadSolverTest_Imaginary",quadSolverTest_Imaginary);
    CU_automated_run_tests();
}
