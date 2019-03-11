#include <stdio.h>
#include <math.h>
#include <string.h>
#include "quadFuncts.h"

int main(int argc, char **argv){
    
    float root1, root2;
    float abc[3];
    int loop = 1;
    
    printf("COMMAND LINE QUADRATIC SOLVER\nBy Tim Hinga and Andrew Crowley\nVERSION 1.0\nType \"help\" for more information\n\n");

    
    do {
        userInput(&abc[0], &abc[1], &abc[2]);
        quadSolve(abc[0], abc[1], abc[2], &root1, &root2);

        loop = runAgain();

    } while(loop);
}
