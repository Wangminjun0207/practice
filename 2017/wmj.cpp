#include <stdio.h>
int main()
{
	int i;
	unsigned long  c;
	c=1;
    for (i=1;i<=50;i++)
	if (i%3==0 && i%2!=0 && i%10!=7)
	{
	c=c*i;
	printf("i=%ld\n,c=%ld\n",i,c);
	}
}
//add some comments
