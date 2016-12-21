#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

//using dev-C++

inline double RingSquare(double r_out,double r_in,double s) 
{
	s=(r_out*r_out-r_in*r_in)*M_PI;
}

int main(int argc, char *argv[]) {
	double r1,r2,s;
	printf("Enter the outside radius: ");
	scanf("%lf",&r1);
	printf ("Enter the inside radius: ");
	scanf("%lf",&r2);
	s=RingSquare(r1,r2,s);
	printf ("ring square is %lf",s);
	_getch();
	return 0;
}

