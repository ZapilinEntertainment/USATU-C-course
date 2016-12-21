#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//using dev-C++


double IterationCalc (int k)
{
	double s=0;
	int i;
	for (i=1;i<=k;i++)
	{
		s+=(2.0*i+3)/(3.0*i-2);
	}
	return(s);
}

double ReccurentCalc (int n)
{
	if (n==1) return 5;
	else return (((2.0*n+3)/(3.0*n-2))+ReccurentCalc(n-1));
}

int main(int argc, char *argv[]) {
	int k=0;
	printf("Enter k: ");
	scanf("%i",&k);
	if (k<=0) {
		printf ("Incorrect input!");
		return(-1);
	}
	else
	{
		printf ("Iteration calculation result: %lf",IterationCalc(k));
		printf ("\nRecurrent calculation result: %lf",ReccurentCalc(k));
	}
	_getch();
	return 0;
}

