#include <stdlib.h> 
#include <string.h>  
#include <stdio.h> 
#include <math.h>
#include "quadSolver.h"
#include "inputValidation.h" 
#include "inputReader.h" 
#include "answerChecker.h"



//Main Method--------------------------------------------------------------------------------------
int main (int argc, char *argv[]) { 

//floats to store result of input validation
float a=0;
float b=0;
float c=0;  

//doubles to pass to quadSolver
double x1;
double x2; 
int cont = 1;

while(cont){
	quadConstants * line = readFromConsole();

	if(line != NULL){

	a = validateInput(line->A);
	b = validateInput(line->B);
	c = validateInput(line->C);

	}else{
		cont = 0;
	}

	quadSolver(a,b,c,&x1,&x2);  


	printWarnings(a,b,c,x1,x2);

}
return 0;
} 
