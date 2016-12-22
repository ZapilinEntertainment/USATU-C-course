#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//using dev-C++
template <class Type> Type Min(Type a,Type b,Type c)
{
	if (a>=b) 
	{
		if (b>=c) return (c);
		else return (b);
	}
	else 
	{
		if (a<c) return (a);
		else return (c);
	}
}
int main(int argc, char *argv[]) {
	int t=0;
	printf("Select arguments type (0 is int, 1 is double, 2 is char): ");
	scanf ("%i",&t);
	switch (t) {
	case 0: {
		printf("Enter arguments: ");
		int x=0,y=0,z=0;
		scanf("%i%i%i",&x,&y,&z);
		printf("minimum is %i",Min(x,y,z));
	break;
	}
	case 1: 
	{		printf("Enter arguments: ");
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		printf("minimum is %lf",Min(a,b,c));
	break;
	}
	case 2: 
	{	printf("Enter arguments:");
		char a,b,c;
		a=getch();
		printf("%c",a);
		b=getch();
		printf("%c",b);
		c=getch();
		printf("%c",c);
		printf("\nminimum is %c",Min(a,b,c));
	break;
	}
	default:
	{
	printf("Type is not defined by program.");
	return(-1);
	break;
	}
	}
	_getch();
	return 0;
}

