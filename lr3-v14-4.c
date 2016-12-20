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
	//for (i;i<length;i++)
//	{
//		printf("%c ",m[i]);
//	}
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
	int i=0,j=0,max=-1,maxpos=0,chosen_pos=1,buffered=0;
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

void BinaryInsertionDescendingSort (char *arr) 
{
	int i,k,middle,right,left;
	char temp;
	for (i=1;i<length;i++)
	{
		left=0;
		right=i;		
		while (right-left>0) 
		{
		middle=(left+right)/2;
		if (arr[i]<arr[middle]) left=middle+1;
		else 
		 {
		 	if (arr[i]==arr[middle]) 
			 {
				 left=middle+1;
				 right=left;
			 }
		 	else 
			 {
			 	right=middle;
			 }
			 
		 }	
		}
		temp=arr[i];
		for (k=i;k>left;k--)
		{
			arr[k]=arr[k-1];
		}
		arr[middle+1]=temp;
	
	}
}



int main(int argc, char *argv[]) 
{
	printf ("set length: ");
	scanf ("%i",&length);
	int upper_bound,lower_bound;
	printf ("(using unsigned char, numbers from 0 to 255)\n");
	printf ("set lower bound: ");
	scanf ("%i",&lower_bound);
	printf ("set upper bound: ");
	scanf ("%i",&upper_bound);
	if (lower_bound>upper_bound||upper_bound<0||lower_bound<0||lower_bound>255||upper_bound>255) 
	{
		printf("incorrect input!");
		_getch();
		return(-1);
	}
	char *m=malloc(length*sizeof(char));
	FillArray(m,upper_bound,lower_bound);
	printf (" unsorted array: \n");
	PrintArray(m);
	BinaryInsertionDescendingSort(m);
	printf("\n sorted array: \n");
	PrintArray(m);
	_getch();
	return 0;
}
