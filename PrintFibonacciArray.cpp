#include <stdio.h>
int main()
{
	long int a,b,c,i;
	a=1;b=1;i=2;
	printf("%10d%10d",a,b);
	while(i<=39)
	{
		c=a+b;
		a=b;
		b=c;
		i++;
		if(i%5==0)
			printf("%10d\n",c);
		else
			printf("%10d",c);
	 } 
}
