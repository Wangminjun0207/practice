
#include <stdio.h>  
#include <string.h> 
void copy(char *p_1,char *p_2,int n)
{
	int j=0;
	for(int i=n-1;p_1[i]!='\0';i++)
	{
		p_2[j]=p_1[i];
		j++; 
	}
	p_2[j]='\0';
}
int main() 
{ 	 
	int n;
	char a[50],b[50];
	scanf("%d",&n);
	scanf("%s",a);
	copy(a,b,n);
	puts(b);
	return 0;
}

