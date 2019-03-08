#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv){
    
    float a, b, c,discriminant, root1, root2;
    int i;
    float abc[3];
    char userInput[100];
    
    printf("COMMAND LINE QUADRATIC SOLVER\nBy Tim Hinga and Andrew Crowley\nVERSION 1.0\nType \"help\" for more information\nType \"q\" to quit program\n");
    
    
    while (strcmp(userInput, "q") != 0){
        do {
       
        printf("Enter coefficients a, b and c (separated each by a space): ");
        fflush(stdin);
        userInput[0] = 0;
        fgets(userInput, 100, stdin);
       //  printf("%s", userInput);
        // printf("%d\n", (int)strlen(userInput));
        userInput[strlen(userInput) - 1] = 0; // this gets rid of the '\n' character, otherwise the strcmp in the nextline won't return 0
        if (strcmp(userInput, "help") == 0) {
            //printHelpMessage();
            printf("help!!!!!!!!!!!\n\n");
            
        }
        else if (strcmp(userInput, "q") == 0) {
            printf("\nExiting Quadratic Solver...done\n");
            return 0;
        }
        else {
            
            char delim[] = " ";

	        char *ptr = strtok(userInput, delim);
            i = 0;
	        while(ptr != NULL) {
		       // printf("%s\n", ptr);
		        sscanf(ptr, "%f", &abc[i]);
		        printf("%lf\n", abc[i]);
		        ptr = strtok(NULL, delim);
	            i++;
	        }
	        
	        a = abc[0];
	        b = abc[1];
	        c = abc[2];
	        
	    printf("%fx^2 + %fx + %f\n\n", a, b, c);
    
        discriminant = (b*b) - (4*a*c);
    
        // condition for real and different rootsq
        if (discriminant > 0)
        {
            // sqrt() function returns square root
            root1 = (-b+sqrt(discriminant))/(2*a);
            root2 = (-b-sqrt(discriminant))/(2*a);
    
            printf("x1 = %.2lf\nx2 = %.2lf\n",root1 , root2);
        }
    
        //condition for real and equal roots
        else if (discriminant == 0)
        {
            root1 = root2 = -b/(2*a);
    
            printf("x1 = x2 = %.2lf\n", root1);
        }
    
        // if roots are not real 
        else
        {
          printf("No real roots present.\n");
        }
        }
        } while (strcmp(userInput, "help") == 0);
        
        
        
        
       
    
    }
    
    
    
    
    return 0;
}
