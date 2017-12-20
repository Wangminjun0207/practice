#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float triangle(float a,float b,float c)
{
	float p,s;
	if(a+b>c && a+c>b && b+c>a)
	{
		p=(a+b+c)/2.0;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("s=%g\n",s);
	 } 
	 else
	 	printf("s=%g\n",s);
}
int main()
{
	float a,b,c;
	printf("请输入三条边长：\n");
	scanf("%f %f %f",&a,&b,&c);
	triangle(a,b,c); 
	return 0;
}
