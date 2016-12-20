#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//using dev-C++
int l=0;

void MassiveSearching(double *m) {
	double negative_sum,positive_sum,number;
	int negative_count=0,positive_count=0;
	int i=0;
	for (i=0;i<l;i++)
	{
	number=*(m+i);
		if (number>0) 
		{
		positive_count++;
		positive_sum+=number;
		}
		else
		{
		if (number<0)
		{
			negative_count++;
			negative_sum+=number;
		}
		}
	}
	if (negative_count>0) {
		printf("\n average negative is %lf",negative_sum/negative_count);
	}
	else 
	{
		printf(" no negatives");
	}
	if (positive_count>0) 
	{
		printf("\n average positive is %lf",positive_sum/positive_count);
	}
		else 
	{
		printf(" no positives");
	}
	_getch();
}

int main(int argc, char *argv[]) 
{
	double *mas;
	printf ("enter numbers count:");
	scanf ("%i",&l);
	if (l<0) 
	{
		printf ("\n incorrect input!");
		_getch();
		return(-1);
	}
	else
	{
		mas=malloc(l*sizeof(double));
		int i=0;
		for (i=0;i<l;i++)
		{
			printf (" a[%i] =",i);
			scanf("%lf",&mas[i]);
		}
		MassiveSearching(mas);
	}
	_getch();
	return 0;
}
