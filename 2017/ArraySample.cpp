#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int (*p)[5])
{
	int i,j,n,k,m,max=0,min=50,temp;
	int a[5][5];
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(max<*(*(p+i)+j))
			{
				max=*(*(p+i)+j);
				n=i;m=j;
			}
	temp=*(*(p+n)+m);*(*(p+n)+m)=*(p[2]+2);*(p[2]+2)=temp;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
				a[i][j]=*(*(p+i)+j);
	for(k=0;k<4;k++)
	{
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(min>a[i][j])
			{
				min=a[i][j];
				n=i;m=j;
			}
		switch(k)
			{
			case 0:temp=*(*(p+n)+m);*(*(p+n)+m)=*(p[0]+0);*(p[0]+0)=temp;break;
			case 1:temp=*(*(p+n)+m);*(*(p+n)+m)=*(p[0]+4);*(p[0]+4)=temp;break;
			case 2:temp=*(*(p+n)+m);*(*(p+n)+m)=*(p[4]+0);*(p[4]+0)=temp;break;
			case 3:temp=*(*(p+n)+m);*(*(p+n)+m)=*(p[4]+4);*(p[4]+4)=temp;break;
			}
			a[n][m]=100;
			min=50;
	}
}
int main()
{
	int i,j,a[5][5];
	srand(time(0));
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			a[i][j]=rand()%51;
		printf("The former Array:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		printf("%4d",a[i][j]);
		printf("\n");
	}
	sort(a);
	printf("The later Array:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		printf("%3d",a[i][j]);
		printf("\n");
	}
	return 0;
}

