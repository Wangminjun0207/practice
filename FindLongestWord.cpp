#include <stdio.h>
int main()
{
	int i,pos=0,word=0,start=0,maxlen=0;
	char string[81];
	gets(string);
	for(i=0;string[i]!='\0';i++)
	if(string[i]==' ') 
	{
		if(word==1 && i-start>maxlen)
		{
			pos=start;
			maxlen=i-start;
		}
		word=0;
	}
		else if(word==0)
		{
			word=1;
			start=i;
		}
		for(i=pos;string[i]!=' '&&string[i]!='\0';i++)
		printf("%c",string[i]);
		printf("\n");	
		return 0;
}
