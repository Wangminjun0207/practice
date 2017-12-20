#include <stdio.h>
int main()
{
	int m,i,flag;
	scanf("%d",&m);
	flag=1;
	for(i=2;i<=m-1;i++)
		{
			if(m%i==0)
			flag=0;
			break;
		}
		if(flag==1)
		printf("Y\n");
		else
		printf("X\n");
	
}
