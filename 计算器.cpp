#include <stdio.h>
float plus(float a,float b)
{
	float c;
	c=a+b;
	return c;
}
float minus(float a,float b)
{
   float c;
   c=a-b;
   return c;	
}
float multi(float a,float b)
{
	float c;
	c=a*b;
	return c;
}
float division(float a,float b)
{
	float c;
	c=a/b;
	return c;
}
int main()
{
	float a,b,c;
	int flag;
	do
	{
		printf("加法请输入1：\n");
		printf("减法请输入2：\n");
		printf("乘法请输入3：\n");
		printf("除法请输入4：\n");
		printf("结束请输入0：\n");
		scanf("%d",&flag);
		printf("请输入参加运算的值：\n");
		scanf("%f %f",&a,&b);
	switch(flag)
	 {
		case 1:;c=plus(a,b);printf("您进行的是加法，结果是： %g\n",c);break;
		case 2:c=minus(a,b);printf("您进行的是减法，结果是： %g\n",c);break;
		case 3:c=multi(a,b);printf("您进行的是乘法，结果是： %g\n",c);break;
		case 4:c=division(a,b);printf("您进行的是除法，结果是： %g\n",c);break;
		case 0:;break;
	 }	
	 printf("\n");
   }while(flag!=0);
}
