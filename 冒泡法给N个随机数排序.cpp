#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N=10;
const int M=10; 
int main()
{
	int a[M][N];
	srand(time(0));
	printf("100个随机数是");
		printf("\n");
	for(int i=0;i<=M-1;i++)
		for(int j=0;j<=N-1;j++)
		{
			a[i][j]=rand()%100;
			printf("a[%d][%d]=%d\t",i,j,a[i][j]);
			if((j+1)%5==0)
				printf("\n");
		} 
} 
