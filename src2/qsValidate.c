//inputValidate.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inputValidation.h"


float validateInput(char * input){

float number; 

if(sscanf(input, "%f", &number) == 1) {
  
} else {
  printf("Error: not a number.\n");
  return 0.0/0.0;
}
return number;
}
