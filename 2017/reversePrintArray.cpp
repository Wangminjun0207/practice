#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void reverse(int *p,int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		if(*(p+i)<*(p+j))
			k=j;
		if(k!=i)
		{t=p[i];p[i]=p[j];p[j]=t;}
	}
}
void printArr(int *p1,int n1)
{
	int i;
	for(i=0;i<n1;i++)
	printf("%d%c",p1[i],((i<n1-1)?' ':'\n'));
}
int main()
{
	int arr[20],i,j,n;
	int *p=arr;
	srand(time(0));
	for(i=0;i<20;i++)
	{
	*(p+i)=rand()%101;
	printf("%d%c",p[i],(i==9|| i==19)?'\n':' ');
	}
	printf("请输入一个整数n:\n");
	scanf("%d",&n);
	reverse(p,n);
	printArr(p,n);
	return 0; 
} 
