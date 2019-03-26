#include "testUserInput.h"

int close(){
    return 0;
}

int init(){
    return 0;
}

void test_userInputGood(){
   int retVal;
   float abc[3];
   abc[0] = 3;
   abc[1] = 4;
   abc[2] = 5;
   retVal = userInput(&abc[0], &abc[1], &abc[2]);
   CU_ASSERT(retVal == 2);
   abc[0] = 22.5436;
   abc[1] = 5432.654;
   abc[2] = 4.123;
   retVal = userInput(&abc[0], &abc[1], &abc[2]);
   CU_ASSERT(retVal == 2);
    
    
}

void test_userInputBad(){
   
    
    
}


int main(int argc, char * argv[]){
	
	CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("test_UserInputSuite",init,close);
    CU_add_test(psuite,"test_userInputGood",test_userInputGood);
   
    CU_automated_run_tests();
}
