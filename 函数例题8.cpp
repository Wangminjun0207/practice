#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void input(int a[])
{
	int i;
	srand(time(0));
	for(i=0;i<100;i++)
	a[i]=rand()%101;
}
void output(int a[])
{
	int i;
	for(i=0;i<100;i++)
	printf("%d ",a[i]);
	printf("\n");
}
void sort(int a[])
{
	int i,j,t;
	for(j=0;j<100;j++)
		for(i=0;i<100-j;i++)
		if(a[i]>a[i+1])
		{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}
	for(i=0;i<100;i++)
	printf("%d ",a[i]);
	printf("\n");
}
void average(int a[])
{
	int sum=0;
	int i;
	for(i=0;i<100;i++)
	sum+=a[i];
	printf("%d\n",sum/100);
}
void max(int a[])
{
	int i;
	int Max=a[0];
	for(i=1;i<100;i++)
	Max=Max>a[i]?Max:a[i];
	printf("%d\n",Max);
}
int main()
{
	int a[100];
	input(a);
	output(a);
	sort(a);
	average(a);
	max(a); 
	return 0;
}
