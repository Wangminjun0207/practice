#include <stdio.h>
void swap(int *p1,int *p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int main()
{
	int a[10],b;
	a[0]=2;
	//double e;
//	int *po1,*po2; 
	//scanf("%d %d",&a,&b);
//	po1=&a;po2=&b;
	//printf("%d  %d\n",po1,po2);
//	if(a<b)
	//swap(po1,po2);
	printf("%d",a);
	return 0;
}
