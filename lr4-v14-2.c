#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//using dev-C++


int main(int argc, char *argv[]) {
	FILE *myText,* outFile;
	myText=fopen("myText.txt","r");
	outFile=fopen("output.txt","w");
	if (myText==NULL)
	{
		printf("error:file cannot be open.");
		_getch();
		return(-1);
	}
	else
	{
		char str[255];
		int i,p1,p2,n;
		while(fgets(str,sizeof(str),myText))
		{
			p1=-1;p2=-1;
			n=strlen(str)-1;
			i=0;
			while (i<n) {
				if (str[i]==' ') {if (p1!=-1) p2=i; else p1=i;}
				i++;
			}
		if (p1!=-1) {
			if (p2==-1) p2=p1;
			for (i=0;i<n-p2-1;i++)
			{
				fputc(str[p2+i+1],outFile);				
			}
			n=i;
			for (i=0;i<=p2-p1;i++)
			{
				fputc(str[p1+i],outFile);
			}
			n+=i;
			for (i=0;i<p1;i++) 
			{
				fputc(str[i],outFile);
			}
			fputc('\n',outFile);
		}
		else fputs(str,outFile);
		}
	}
	fclose(myText);
	fclose (outFile);
	return 0;
}
