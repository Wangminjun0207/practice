#include <stdio.h> 
#include <math.h>
double fun(int n)
{
	int i, j;
	double s;
	int flag = 1;
	for(j=3;j<=n;j++)
	for(i=2;i<j;i++)
	{
		if(j%i==0)
			flag = 0;
		if(flag == 1)
			s += sqrt(j);
		flag = 1; 
	}
	return s;
}
int main()
{
	int n;
	double sum; 
	scanf("%d",&n);
	sum = fun(n);
	printf("%f\n",sum);
	return 0;
}
