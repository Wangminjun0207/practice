#include <stdio.h>  
int main() 
{ 	 
	int n,i=0,j=0;
	int flag=0;
	char a[50],b[50];
	scanf("%s",a);
	scanf("%s",b);
	while(b[i]!='\0')
	{
		if(a[j]==b[i])
			for(;a[j]!='\0';j++)
			{
				if(a[j]==b[i++])
					flag=1;
				else
					flag=0;
			}
		i++;
		if(flag==1)
		break;
		else
		j=0; 
	}
	if(flag==1)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
} 
