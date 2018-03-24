#include <stdio.h>
long Fact(int);
long Comb(int , int);
int main(int argc, char *argv[])
{
	int m,k;
	do{
		puts("Please input m,k :");
		scanf("%d%d",&m,&k);
	}while(m<0 || k<0 || m<k);
	printf("%ld\n",Comb(m,k));
	return 0;
} 
/*******************************************
主涵数可以用以下代码替换 :
int main(int argc, char *argv[])
{
	int m,k;
	long s; 
	do{
		puts("Please input m,k :");
		scanf("%d%d",&m,&k);
	}while(m<0 || k<0 || m<k);
	s=Comb(m,k);
	printf("%ld\n",s);
	return 0;
} 
*******************************************/
long Comb(int a, int b)
{
	long result;
	result = Fact(a)/(Fact(b)*Fact(a-b));
	return result;
}

long Fact(int a)
{
	long result;
    if(a==0 || a==1)
		return 1;
	else
		result = a*Fact(a-1);
	return result;
}
/***********************************************
利用函数的递归求组合数，也可以利用一下代码替换：
 long Fact(int a)
{
	long result=1;
    for(int i=1;i<a;i++)
    result = result * i;
	return result;
}
迭代也完全可以实现阶乘计算的功能 
************************************************/ 
