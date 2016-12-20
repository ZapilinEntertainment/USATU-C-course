#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//using dev-C++


int main(int argc, char *argv[]) {
	FILE *myText;
	int string_index=0,words_count=0;
	myText=fopen("myText.txt","r");
	if (myText==NULL)
	{
		printf("error:file not found");
		_getch();
		return(-1);
	}
	else
	{
		char x,str[255];
		while(fgets(str,sizeof(str),myText))
	{
		string_index++;
		if (string_index%2==0)
		{
			int i,n,prev_space_pos=-1;
			n=strlen(str);
			printf(" %s",str);
			for (i=0;i<n;i++)
			{
				x=str[i];
				if (x==' '||i==n-1)
				{
					if (i-prev_space_pos>1) 
					{
						words_count++;
						prev_space_pos=i;
					}
				}
			}
		}
	}
	}
	fclose(myText);
	printf("\n %i words",words_count);
	_getch();
	return 0;
}
