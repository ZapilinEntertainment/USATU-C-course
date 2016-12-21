#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//using dev-C++
template <class Type> Type Min (T a,T b,T c)
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
	int type=0;
	printf("Select arguments type (0 is int, 1 is double, 2 is char): ");
	scanf ("%i",type);
	printf("Enter arguments: ");
	switch (type):
	case 0: 
		int a,b,c;
		scanf("%i%i%i",%a,&b,&c);
		printf("minimum is %i",Min(a,b,c));
	break;
	case 1: 
		double a,b,c;
		scanf("%lf%lf%lf",%a,&b,&c);
		printf("minimum is %lf",Min(a,b,c));
	break;
	case 2: 
		char a,b,c;
		scanf("%c%c%c",%a,&b,&c);
		printf("minimum is %c",Min(a,b,c));
	break;
	default:
	printf("Type is not defined by program.");
	return(-1);
	break;
	_getch();
	return 0;
}

