#include "quadFuncts.h"

/** Function that will receive user input, and assign the floats to pointed to in parameters.
*/
void userInput(float *a, float *b, float *c) {

	char input[100];

	printf("Enter coefficients a, b and c (separated each by a space): ");
    fpurge(stdin);
    fgets(input, 100, stdin);  //Get a line of input

    while (sscanf(input, "%f %f %f", a, b, c) != 3) { //Check for 3 floats.
    	if (strncmp(input, "help", 4) == 0) { //Check for help command.
    		helpFunction();
    		fpurge(stdin);
    		printf("Enter coefficients a, b and c (separated each by a space): ");  //Return to trying to get user input.
    		fgets(input, 100, stdin);
    	}
    	else {
    		printf("Error in formatting. Please enter 3 real numbers. \n> ");  //Warning & receive user input again.
    		fpurge(stdin);
    		fgets(input, 100, stdin);
    	}
    }

}

//Simple help function to assist the user.
void helpFunction() {
	printf("To use: simply provide 3 real numbers, each with a space in between. The program will handle the rest.\n");
}


void quadSolve(float a, float b, float c, float *root1, float *root2) {

	float discriminant;
	printf("\nThe quadratic function to be solved: %fx^2 + %fx + %f\n\n", a, b, c);

	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				printf("All real numbers are roots.\n");
			else
				printf("Unsolvable equation.\n");
		}
		else
			printf("This is a linear equation with root = %f\n", -c/b);
	}

	else { 

   		discriminant = (b*b) - (4*a*c);

		// condition for real and different rootsq
    	if (discriminant > 0) {
            	// sqrt() function returns square root
            	*root1 = (-b+sqrt(discriminant))/(2*a);
            	*root2 = (-b-sqrt(discriminant))/(2*a);
    
            	printf("x1 = %f\nx2 = %f\n", *root1 , *root2);
        }

    	//condition for real and equal roots
    	else if (discriminant == 0) {
            *root1 = *root2 = -b/(2*a);
    
            printf("x1 = x2 = %.2lf\n", *root1);
        }

    	else
    		printf("No real roots present.\n");
	}	
}


int runAgain() {
	char input[10];
	int retVal = -1;
	int loop = 1;

	printf("\nRun Quadratic Solver Again? ('y' for Yes, 'n' for No) : ");
    
    fpurge(stdin);   
    fgets(input, 10, stdin);
    
    while (loop) {
    	if (strncmp(input, "y", 1) == 0) {
    		loop = 0;
    		retVal = 1;
    	}
    	else if (strncmp(input, "n", 1) == 0) {
    		loop = retVal = 0;
    	}
    	else {
    		fpurge(stdin);
    		printf("\nPlease enter a valid response.\nRun Quadratic Solver Again? ('y' for Yes, 'n' for No) : ");
    		fgets(input, 10, stdin);
    	}

    }
    return retVal;
}




























