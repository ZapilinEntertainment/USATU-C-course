#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//using dev-C++
	float percentum=0;
	int start_year,end_year;
	int start_month,end_month;
	int current_year, current_month;
	int months_length=0;
	int start_quartal=1;
	int quartals_length=0;
	
	int stages_count=7;
	float *stages_ends;

int MonthsBetween (int year_start, int year_end, int month_start, int month_end)
{
	return((year_end-year_start)*12-month_start+month_end);
}

int main(int argc, char *argv[]) {
	
	printf("enter start date (year month) \n");
	scanf ("%i%i",&start_year,&start_month);
	printf("enter end date (year month) \n");
	scanf ("%i%i",&end_year,&end_month);
	
	months_length=MonthsBetween(start_year,end_year,start_month,end_month);
	
	printf("enter current date (year month) \n");
	scanf("%i%i",&current_year,&current_month);
	start_quartal=start_month/4+1;
	quartals_length=months_length/3;

	
	percentum=MonthsBetween(start_year,current_year,start_month,current_month);
	percentum/=months_length;
	
	printf("month: %i of %i \n", (int)(percentum*months_length), months_length);
	printf("progress: %f percent \n",percentum*100);
	int x=start_quartal+percentum*quartals_length;
	x%=4;
	if (x==0) x=4;	
	printf("quartal: %i \n",x);
	
	printf ("check the stages? 1/0 \n");
	x=-1;
	scanf("%i",&x);
	if (x!=1) return (0);
	printf("enter stages count \n");
	scanf("%i",&stages_count);
	if (stages_count>0) stages_ends=new float[stages_count-1]; else return(-1);
	int yr=0, mth=0;
	for (int i=0; i<stages_count-1; i++)
	{
		printf("enter end of stage %i (year month): ",i+1);
		scanf ("%i%i",&yr,&mth);
		stages_ends[i]=MonthsBetween(start_year,yr,start_month,mth)/((float)(months_length));
	}
	x=stages_count;
	for (int i=0;i<stages_count-1;i++)
	{
		if (percentum>stages_ends[i]) {x=i+1;break;}
	}
	printf("\n Current stage: stage %i",x);
	
	return 0;
}



