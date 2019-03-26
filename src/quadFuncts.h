#ifndef QUAD_FUNCTS
#define QUAD_FUNCTS

#include <string.h>
#include <stdio.h>
#include <math.h>

extern void userInput(float *a, float *b, float *c);
extern void helpFunction();
extern int quadSolve(float a, float b, float c, float *root1, float *root2);
extern float citardauqFormula(float a, float b, float c, int positive);

extern int approxZero(float z);
extern int runAgain();





#endif
