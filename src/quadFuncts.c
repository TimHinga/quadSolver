#include "quadFuncts.h"

int qsGetLine(char *line, int nline) {
    int retVal = 0;
    printf("Enter coefficients a b c (each separated by a space): ");
    fflush(stdin);
    if (fgets(line, nline, stdin) == NULL) {
        retVal = -1;
    }
    line[strlen(line)-1] = '\0';
    return retVal;
}

int qsValidate(char *line, int nline, double *a, double *b, double *c) {
    int retVal = 0;

    char *token;
    char *endptr;
    token = strtok(line, " ");
    int n = 0;
    int decimalDigits = 0;
    double temp = 0;

    if (!strncmp(token, "help", 4)) {
        retVal = 1;
        token = NULL;
    }

    while (token) {
        for (int i = 0; i < strlen(token) && i < nline; i++) {
            if ( (int) token[i] == (int) '.' ) {
                decimalDigits = strlen(token) - (i+1);      //Count number of digits after the decimal.
                i = strlen(token);
            }
        }

        if (decimalDigits > 8) {     //If more than 8 digits
            printf("Please make sure all numbers have 8 or less decimal places.\n");
            n = 3;
            retVal = -1;
            token = NULL;
        }

        else {
            errno = 0;
            temp = strtod(token, &endptr);
            if (errno != 0 || *endptr != '\0') {     //If the string is an invalid input. E.g. has non-numeric characters.
                printf("Invalid inputs.\n");
                n = 3;
                retVal = -1;
                token = NULL;
            }
            else if (temp > FLT_MAX || temp < -FLT_MAX) {    //If the string is not within the range of floats.
                printf("Please provide inputs within the range of 32 bit floating points.\n");
                n = 3;
                retVal = -1;
                token = NULL;
            }

            else {     //String is all good to go, check next input.
                token = strtok(NULL, " ");
                switch (n) {
                    case 0: 
                        *a = temp;
                        break;
                    case 1: 
                        *b = temp;
                        break;
                    case 2:
                        *c = temp;
                        break;
                    default:
                        printf("Please enter only 3 inputs for a b c\n");
                        retVal = -1;
                        token = NULL;
                        break;
                    }
                n++;
            }
        }
    }
    if (n < 3) {
        printf("Please enter 3 inputs for a b c\n");
        retVal = -1;
    }
    return retVal;
}

//Simple help function to assist the user.
void qsHelp() {
    printf("To use: simply provide 3 IEEE-Floating Point 32 bit normalized values, with no more than 8 decimal places, "
        "each with a space in between.\n");
}

int qsSolve(double a, double b, double c, double *root1, double *root2) {

    double discriminant;
    int retVal = 0;

    printf("\nThe quadratic function to be solved: %.8lfx^2 + %.8lfx + %.8lf\n\n", a, b, c);

    if (approxZero(a)) {
        if (approxZero(b)) {
            if (approxZero(c))
                printf("All real numbers are roots.\n");
            else
                printf("Unsolvable equation.\n");
        }
        else
            printf("This is a linear equation with root = %lf\n", -c/b);
    }

    else { 
        discriminant = (b*b) - (4*a*c);

        // condition for real and different roots
        if (discriminant > 0) {
            if (b > 0) {
                *root1 = (-b-sqrt(discriminant))/(2*a);
                *root2 = citardauqFormula(a,b,c, 0);
            }
            else {
                *root1 = (-b+sqrt(discriminant))/(2*a);
                *root2 = citardauqFormula(a,b,c, 1);
            }
            retVal = 1;        
        }

        //condition for real and equal roots
        else if (discriminant == 0) {
            *root1 = *root2 = -b/(2*a);
            retVal = 2;
        }

        else
            retVal = 3;
    }
    return retVal;
}

double citardauqFormula(double a, double b, double c, int positive) {
    double r = sqrt(b*b - 4*a*c);
    if (positive) {
        return ((2*c) / (-b+r));
    }
    else
        return ((2*c) / (-b-r));
}

int qsResults(double x1, double x2, int i) {

    int retVal = 0;

    switch (i) {
        case 1:
            printf("Equation has two unique real roots:\nx1 : %.8lf\nx2 : %.8lf\n", x1, x2);
            break;
        case 2:
            printf("Equation has identical roots:\nx1 = x2 = %.8lf\n", x1);
            break;
        case 3:
            printf("Equation has no real roots.\n");
            break;
        default:
            printf("Internal Error.");
            retVal = -1;
        }

    return retVal;
}



int runAgain() {
	char input[10];
	int retVal = -1;
	int loop = 1;

	printf("\nRun Quadratic Solver Again? ('y' for Yes, 'n' for No) : ");
    
    fflush(stdin); 
    fgets(input, 10, stdin);
    
    while (loop) {
    	if (strncmp(input, "y", 1) == 0) {
    		loop = 0;
    		retVal = 1;
    	}
    	else if (strncmp(input, "n", 1) == 0) {
    		printf("Exiting...\n");
    		loop = retVal = 0;
    	}
    	else {
    		#ifdef MAC
    		fpurge(stdin);
    		#else
    		fflush(stdin);
    		#endif
    		printf("\nPlease enter a valid response.\nRun Quadratic Solver Again? ('y' for Yes, 'n' for No) : ");
    		fgets(input, 10, stdin);
    	}

    }
    return retVal;
}

//returns 1 if z is within 0.0000001 of zero, else returns 0
int approxZero(double z){
	return (z < 0.0000001 && z > -0.0000001)? 1 : 0;
}






















































