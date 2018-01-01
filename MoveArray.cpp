#include <stdio.h> 
#include <stdlib.h>
void move(int *p,int n,int k)
{
	int i,t,*r=p;
	for(i=1;i<=k;i++)
	{		
		t=*(r+n-1);
		for(r=p+n-1;r>p;r--)
		*r=*(r-1);
		*r=t;
	}
}
int main()
{
	int a[100];
	int *p;
	int m,n;
	scanf("%d%d",&n,&m);
	for(p=a;p<a+n;p++)
		scanf("%d",p);
	move(a,n,m);
	for(p=a;p<a+n;p++)
		printf("%3d",*p);
	printf("\n");
	return 0;
}
