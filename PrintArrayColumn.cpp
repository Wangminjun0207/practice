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
		for(int j=0;j<=N-1;j++)
		for(int i=0;i<=M-1;i++)
		{
			a[j][i]=rand()%100;
			printf("a[%d][%d]=%d%c",j,i,a[j][i],((i+1)%10==0)?'\n':' ');
		} 
}  
