#include <stdio.h>
int main()
{
	int a[5][6];
	int i,j,c=0,p,q,m,n,flag;
	for(i=0;i<5;i++)
	for(j=0;j<6;j++)
	scanf("%d",&a[i][j]);
	for(i=0;i<5;i++)
	for(j=0;j<6;j++)
	{
		flag=1;
		for(p=0;p<6;p++)
		if(a[i][j]<a[i][p])
		flag=0;
		if(flag==1)
		for(q=0;q<5;q++)
		if(a[i][j]>a[q][j])
		flag=0;
		if(flag==1)
			{
				printf("%d %d\n",i+1,j+i);
				c=1;
			}
	}
	if(c==0)
	printf("none\n");
	return 0;
}

