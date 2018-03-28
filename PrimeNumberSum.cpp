#include <stdio.h>
#include <math.h>
// 求 3~n （包括3和 n）所有素数的平方和 
float func(int n)
{
	int i,j,flag;
	float result = 0;
	flag = 1;
	for(i=3; i<=n; i++)
	{
		for(j=2; j<n; j++)
		{
			if(i%j == 0)
			{
				flag = 0;
				break;
			}	
		}
		if(flag == 1)
			result = result + sqrt((float)i);//此步骤有问题 
		//printf("result = %f\n",sqrt(i));
		flag = 1;
	}
	return result;
}
int main()
{
	int n;
	printf("Input anumber :");
	scanf("%d",&n);
	printf("result = %f\n",func(n));
	return 0;
}
