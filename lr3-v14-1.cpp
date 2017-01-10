#include "stdlib.h"
#include "conio.h"
#include "stdio.h"

int main(int argc, char* argv[])
{
	double l=0, h=0;
	printf("enter length and height\n");
	scanf("%lf%lf",&l,&h);
	if (l <= 0 || h <= 0)
	{
		printf("incorrect input!");
		_getch();
		return (-1);
	}
	double &length = l, &height = h;
	printf("square is %lf",length*height);
	_getch();
	return 0;
}

