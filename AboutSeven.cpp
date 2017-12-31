#include <stdio.h>
int main()
{
	int n;//n<=100 
	double sum=0;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
		if(i%7!=0 && i%10!=7 && i/10!=7)
			sum+=i*i;
		printf("%g\n",sum);
	return 0;
}

