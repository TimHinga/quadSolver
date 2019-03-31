#include <stdlib.h> 
#include <string.h>  
#include <stdio.h> 
#include <math.h>
#include "qsSolve.h"
#include "qsValidate.h" 
#include "qsGetLine.h" 
#include "answerChecker.h"




int main (int argc, char *argv[]) { 

//floats to store result of input validation
float a = 0;
float b = 0;
float c = 0;  

//doubles to pass to quadSolver
double x1;
double x2; 
int contin = 1;

while(cont){
	constants * line = readLine();
	if (line != NULL) {
		a = validateInput(line->A);
		b = validateInput(line->B);
		c = validateInput(line->C);
	}
	else{
		contin = 0;
	}

	quadSolver(a,b,c,&x1,&x2);
	displayWarnings(a,b,c,x1,x2);

}
return 0;
} 
