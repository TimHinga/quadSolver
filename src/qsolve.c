#include "quadFuncts.h"

int main(int argc, char **argv){
    
    double x1, x2;
    double a, b, c;
    int loop = 1;

    char line[100];

    int i;
    
    printf("COMMAND LINE QUADRATIC SOLVER\nBy Tim Hinga and Andrew Crowley\nVERSION 1.0\nType \"help\" for more information\n\n");

    
    do {
        
        if (qsGetLine(line, 100)) {
            printf("Failed to receive user inputs.");
        }

        while ((i = qsValidate(line, 100, &a, &b, &c)) != 0) {
            if (i == 1)
                qsHelp();
            if (qsGetLine(line, 100))
                printf("Failed to receive user inputs.");
        }        

        i = qsSolve(a, b, c, &x1, &x2);
        if (i) {
            if (qsResults(x1, x2, i))
                loop = 0;
            else
                loop = runAgain();
        }
        else
            loop = runAgain();

    } while(loop);

    return 0;
}
