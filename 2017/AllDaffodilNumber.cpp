#include <stdio.h>
int area(int r)
{
	float s;
	s=3.14159*r*r;
	return s;
}
void print()
{
	printf("************\n");
			return ;
	printf("############\n");
}
int main()
{
	int r,s;
	scanf("%d",&r);
	s=area(r);
	print();
	printf(" area = %d\n",s);
	print();
	return 0;
}
