#include <stdio.h>
int main()
{
	int r;
	scanf("%d",&r);
	int a,b,c;
	a=r/100;
	b=r%100/10;
	c=r%10;
	if(r==a*a+b*b+c*c)
	printf("%d是水仙花数！\n",r);
	else
	printf("%d不是水仙花数！\n",r);
	return 0;
}
