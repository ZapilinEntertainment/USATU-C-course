#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//using dev-C++


int main(int argc, char *argv[]) {
	FILE *myText,*outFile;
	int i=0,string_index=0,max_length=0;
	char str[255];
	myText=fopen("myText.txt","r");
	if (myText==NULL)
	{
		printf("error:file not found");
		_getch();
		return(-1);
	}
	else
	{
		while(fgets(str,sizeof(str),myText))
	{
		if (strlen(str)>max_length)
		{
			string_index=i;
			max_length=strlen(str);
		}
		i++;
	}
	if (i==0) 
	{
		printf("This file was empty.");
		_getch();
		return(0);
	}
	else
	{
		rewind(myText);
		fopen("output.txt","w");
		for (int j=0;j<i;j++) 
		{
		fgets(str,sizeof(str),myText);
		printf("%s",str);
			if (j!=string_index) 
			{
				fprintf(outFile,"%s",str);			
			}	
			else
			{				
				fprintf(outFile,"s"," ");
			}
			
		}
		fclose(outFile);
	}
	}
	fclose(myText);
	return 0;
}
