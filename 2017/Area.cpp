#include "stdio.h"
int main()
{
	char str1[50];
	char str2[50];
	int i,j=0;
	gets(str2);
	for(i=0;str2[i]!='\0';i++)
		if(str2[i]>='a' && str2[i]<='z')
			{
				str1[j]=str2[i];
				j++;
			}
			str1[j]='\0';
	puts(str1);
	puts(str2);
	return 0;
} 
