#include "test_qsGetLine.h"


int close() {
    return 0;
}

int init(){
    stdin = freopen("getLineSTDIN","r",stdin);
    return 0;
}



void test_qsGetLine() {
    char *line;
    line = malloc(16 * sizeof(char));
    int nline;
    int retVal;
    retVal = qsGetLine(line, 100);
    CU_ASSERT(retVal == 0);
    printf("\n");
    retVal = qsGetLine(line, 100);
    CU_ASSERT(retVal == 0);
    printf("\n");
    retVal = qsGetLine(line, 100);
    CU_ASSERT(retVal == 0);
    printf("\n");
    retVal = qsGetLine(line, 100);
    CU_ASSERT(retVal == 0);
    printf("\n");
    retVal = qsGetLine(NULL, 100);
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

    psuite = CU_add_suite("qsGetLineSuite",init,close);
    CU_add_test(psuite,"qsGetLine",test_qsGetLine);
    CU_automated_run_tests();
}