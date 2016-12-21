#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//using dev-C++

double SquareCalc (double s,double h);

void PrintResult (double x) {
	printf ("The volume is %lf",x);
}

int main(int argc, char *argv[]) {
	double s,h;
	printf ("Enter the square: ");
	scanf ("%lf",&s);
	if (s<=0) {
		printf ("incorrect input!");
		return(-1);
	}
	printf("Enter the height: ");
	scanf("%lf",&h);
	if (h<=0) {
		printf ("incorrect input!");
		return(-1);
	}
	PrintResult(SquareCalc(s,h));
	_getch();
	return 0;
}

double SquareCalc (double s,double h)
{
	return(s*h);
}
