#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

//using dev-C++
int length=0;

inline void PrintArray (char *m) 
{
	int i=0;
	printf ("\n");
	for (i=0;i<length;i++)
	{
		printf("%i ",(int)m[i]);
	}
}

void FillArray (char *m,int up,int lowest)
{
	int i=0;
	int d=up-lowest; //diapason
	double dx; char val;
	srand ( time(NULL) ); 
	for (i;i<length;i++)
	{
		dx=(double)(rand());
		dx/=RAND_MAX;
		dx*=d;
		dx+=lowest;
		val=(char)dx;
		m[i]=val;
	}
}

void InsertionDescendingSort(char *m)
{
	int i=0,j=0,max=-256,maxpos=0,buffered=0;
	for (i;i<length-1;i++)
	{
		max=m[i];
		maxpos=i;
		for (j=i+1;j<length;j++) 
		{		
			if (m[j]>max)
			{
				max=m[j];
				maxpos=j;
			}
		}
		if (maxpos!=i) 
		{
			buffered=m[i];
			m[i]=max;
			m[maxpos]=buffered;
		}
	}
}




int main(int argc, char *argv[]) 
{
	printf ("set length: ");
	scanf ("%i",&length);
	int upper_bound,lower_bound;
	printf ("(using signed char, numbers from -128 to 127)\n");
	printf ("set lower bound: ");
	scanf ("%i",&lower_bound);
	printf ("set upper bound: ");
	scanf ("%i",&upper_bound);
	if (lower_bound>upper_bound||upper_bound<-128||lower_bound<-128||lower_bound>127||upper_bound>127) 
	{
		printf("incorrect input!");
		_getch();
		return(-1);
	}
	char *m=malloc(length*sizeof(char));
	FillArray(m,upper_bound,lower_bound);
	printf (" unsorted array: \n");
	PrintArray(m);
	InsertionDescendingSort(m);
	printf("\n sorted array: \n");
	PrintArray(m);
	_getch();
	return 0;
}
