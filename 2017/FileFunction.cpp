#include <stdio.h> 
#include <stdlib.h>
int swapInt(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("%d,%d\n",a,b);
	return 0;
}

int main(int argc,char *argv[])
{
	int a =10;
	int b = 30;
	printf("%d,%d\n",a,b);
	swapInt(a,b);
}
