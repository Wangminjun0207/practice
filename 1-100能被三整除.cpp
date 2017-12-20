#include <stdio.h>
int main()
{
	int i;
	for (i=1;i<=100;i++)
    if (i%3==0 && i%2!=0 && i%10!=7) 
	printf("%d\n",i);
}
