#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//using dev-C++


int main(int argc, char *argv[]) {
	FILE *myText;
	int spaces_count=0;
	myText=fopen("myText.txt","r");
	if (myText==NULL)
	{
		printf("error:file cannot be open.");
		_getch();
		return(-1);
	}
	else
	{
		char str[255];
		int i,n,k=0;
		while(fgets(str,sizeof(str),myText))
		{
			k++;
			if (k%2==1) {			
			n=strlen(str);
			i=0;
			while (i<n) {
				if (str[i]==' ') spaces_count++;
				i++;
			}
			}
		}
	}
	fclose(myText);
	printf("%i spaces",spaces_count);
	_getch();
	return 0;
}
