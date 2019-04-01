#ifndef QUAD_FUNCTS
#define QUAD_FUNCTS

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <float.h>

extern int qsGetLine(char *line, int nline);
extern int qsValidate(char *line, int nline, double *a, double *b, double *c);
extern void qsHelp();
extern int qsSolve(double a, double b, double c, double *root1, double *root2); 
extern double citardauqFormula(double a, double b, double c, int positive);
extern int qsResults(double x1, double x2, int i); 

extern int approxZero(double z);
extern int runAgain();





#endif
