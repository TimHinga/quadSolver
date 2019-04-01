#include "test_qsResults.h"


int close() {
    return 0;
}

int init(){
    return 0;
}



void test_qsResults() {
    int retVal;
    retVal = qsResults(1, 2, 1);
    CU_ASSERT(retVal == 0);
    printf("\n");
    retVal = qsResults(1, 2, 2);
    CU_ASSERT(retVal == 0);
    printf("\n");
    retVal = qsResults(1, 2, 3);
    CU_ASSERT(retVal == 0);
    printf("\n");
    retVal = qsResults(1, 2, 4);
    CU_ASSERT(retVal == -1);
    printf("\n");

}






int main(int argc, char * argv[]){
	
	CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("qsResultsSuite",init,close);
    CU_add_test(psuite,"qsResults",test_qsResults);
    CU_automated_run_tests();
}