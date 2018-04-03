#include <stdio.h>
void swap(int x,int y)
{
	int t;
	t=x;
	x=y;
	y=t;
	printf("%d  %d\n",x,y);
}
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	swap(a,b);
	printf("%d  %d\n",a,b);
	return 0;
}
