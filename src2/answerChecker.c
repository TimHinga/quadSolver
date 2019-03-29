#include "answerChecker.h"

//returns 0 if x is accurate, -1 if 0.999x is more accurate, and 1 if 1.001x is more accurate to indicate that the solution may be inaccurate

int checkAnswer(double a, double b, double c, double x){
	double val = fabs((a * x * x) + (b * x) + c);
	double xSmall = 0.999 * x;
	double valSmall = fabs((a * xSmall * xSmall) + (b * xSmall) + c);
	double xBig = 1.00001 * x;
	double valBig = fabs((a * xBig * xBig) + (b * xBig) + c);

	if(val <= valSmall && val <= valBig){
		return 0;
	}
	else if(val > valSmall){
		return -1;
	}
	else{
		return 1;
	}
}
