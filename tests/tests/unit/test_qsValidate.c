#include "test_qsValidate.h"


int close() {
    return 0;
}

int init(){
    stdin = freopen("validateSTDIN","r",stdin);
    return 0;
}

void test_qsValidate() {
    int retVal;
    double a, b, c;
    char * line;
    line = malloc(32 * sizeof(char));
    qsGetLine(line, 100);
    retVal = qsValidate(line, 100, &a, &b, &c);
    CU_ASSERT(retVal == 0);
    printf("\n");
    
    qsGetLine(line, 100);
    retVal = qsValidate(line, 100, &a, &b, &c);
    CU_ASSERT(retVal == -1);
    printf("\n");
    
    qsGetLine(line, 100);
    retVal = qsValidate(line, 100, &a, &b, &c);
    CU_ASSERT(retVal == -1);
    printf("\n");
    
    qsGetLine(line, 100);
    retVal = qsValidate(line, 100, &a, &b, &c);
    CU_ASSERT(retVal == -1);
    printf("\n");
    
    qsGetLine(line, 100);
    retVal = qsValidate(line, 100, &a, &b, &c);
    CU_ASSERT(retVal == -1);
    printf("\n");
    
    qsGetLine(line, 100);
    retVal = qsValidate(line, 100, &a, &b, &c);
    CU_ASSERT(retVal == -1);
    printf("\n");
    
    
    free(line);
    
}

int main(int argc, char * argv[]){
	
	CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("qsValidateSuite",init,close);
    CU_add_test(psuite,"qsValidate",test_qsValidate);
    CU_automated_run_tests();
}