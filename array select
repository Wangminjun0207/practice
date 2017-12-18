#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
const int N=20;
int main()
{
	int a[N],t,sum;
		srand(time(0));
		printf("%d个随机数组：\n\n",N);
	for(int i=0;i<=N-1;i++)
		{
			a[i]=rand()%100;
			printf("a[%d]=%-7d\t",i,a[i]);
			if((i+1)%5==0) 
				printf("\n");
		}	
	for(int i=1;i<=N-1;i++)
		for(int j=0;j<=N-1-i;j++)
			{
				if(a[j]>a[j+1])
					{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
					}
			}
				printf("\n冒泡法排序后的随机数组：\n\n");
	for(int i=0;i<=N-1;i++)
			{
			sum+=a[i];
			printf("a[%d]=%-7d\t",i,a[i]);
			if((i+1)%5==0)
			printf("\n");
			}
			printf("\nsum=%d\n",sum);
}
