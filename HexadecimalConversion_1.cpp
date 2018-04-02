#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
int countw;
//************************
int start()//开始界面
{
	system("color 3f");
	printf("\t****************************\n");
	printf("\t============================\n");
    printf("\t====《1.十进制转二进制》====\n");
	printf("\t====《2.二进制转十进制》====\n");
	printf("\t====《3.十进制转八进制》====\n");
	printf("\t====《4.八进制转十进制》====\n");
	printf("\t====《5.十进制转十六进制》==\n");
	printf("\t====《6.十六进制转十进制》==\n");
	printf("\t============================\n");
	printf("\t****************************\n");
		return 0;
}
//***************************************

int ten_two1(double x)//整数部分
{int n=(int)x;
	if(n>=0)
	{
		int temp=n/2;
		int count=0,a[32];
		a[count]=n%2;
		while(temp!=0)//余数不为零;算法：除2取余
		{
			a[count+1]=temp%2;
			temp=temp/2;
			count++;
		}
		printf("%f的二进制数:",x);
		for(;count>=0;count--)
			printf("%d",a[count]);
	}
	if(n<0)
	{
		long t=-n;
		int temp;
		int count=0,a[32];
		temp=t/2;
		a[count]=t%2;
		while(temp!=0)
		{
			a[count+1]=temp%2;
			temp=temp/2;
			count++;
		}
		printf("%f的二进制数:-",x);
		for(;count>=0;count--)
			printf("%d",a[count]);
	}
     printf(".");
	return 0;
}
//**********************************
int ten_two2(double num)//小数部分
{   num=fabs(num);
	long x=(long)num;
	num=num-x;
	int n[32]={0},i=0,j;
	num=num*2;
	n[i]=(int)num;
	num=num-(int)num;


		while(i<countw-1)//保留几位小数
		{    i++;
			num=num*2;
			n[i]=(int)num;
			num=num-(int)num;//取小数部分
		}
		for(j=0;j<=i;j++)
			printf("%d",n[j]);
		
	return 0;
}
//***************************
//二进制转换十进制
int two_ten()
{system("cls");
	printf("输入二进制数:");
    char a[16],b[16],c[16];
	scanf("%s",a);
	double temp=0;
	int sum=0,i=0,j=0,k=0,t;
	//截取整数部分到数组b
	while(a[i]!='\0')
	{
		b[j]=a[i];
		j++;
		i++;
		if(a[i]=='.')
			break;
	}
	b[j]='\0';//字符串后加结束字符
    t=j+1;//直接取出小数点后的数到数组c

	while(a[t]!='\0')
	{
		c[k]=a[t];
		k++;
		t++;
	}
	c[k]='\0';
	//printf("\t%s\t",c);


	for(i=strlen(b)-1;i>=0;i--)
	{
		if(b[i]=='1')
		{
			sum+=(int)pow(2,i+1);
		}
	}
	//小数部分
     i=0;
	while(c[i]!='\0')
	{
		temp+=pow(2,-(i+1));
		i++;
	}

	
	printf("%s的十进制是:%f",a,sum+temp);
return 0;}
//************十进制转二进制
int ten_eight()
{
	system("cls");
	printf("请输入十进制数:");
	double x;
	int n,count,a[32];
	scanf("%lf",&x);
    printf("请输入小数点后保留位数:");
    scanf("%d",&countw);
//****************整数部分
	n=(int)x;
	if(n>=0)
	{
		count=0;
		a[count]=n%8;
		n=n/8;
		while(n!=0)
		{
			count++;
			a[count]=n%8;
			n=n/8;
		}
		printf("%f的八进制数：",x);
		for(;count>=0;count--)
		{
			printf("%d",a[count]);
		}
//****小数部分
		double m;
		m=x-(int)x;//printf("\t%f\t",m);
		int b[16],i=0;
		b[i]=(int)(m*8);//乘8取整
		m=m*8-b[i];	
		while(i<=countw-2)
		{
			i++;
			b[i]=(int)(m*8);
			m=m*8-b[i];
		}
		printf(".");
		//printf("i=%d\n",i);
		for(int j=0;j<=i;j++)
			printf("%d",b[j]);

	}
return 0;}

//八进制转十进制
int eight_ten()
{    char w[16]={0};
     int a=0,n;
	printf("请输入八进制数:");
	scanf("%s",&w);
//	puts(w);
	n=strlen(w);
	for(int i=0;i<=strlen(w)-1;i++)
	{
		a+=(w[i]-'0')*pow(8,n-1);
		n--;
	}
	printf("%s的十进制为:%d",w,a);
	
return 0;}


int ten_sixteen()
{   int n,temp,i=0,j,t;
    char  a[16]; 
	system("cls");
	printf("请输入十进制数:");
	scanf("%d",&n);
	t=n%16;
	if(t>9)
		a[i]=t+'a'-10;
	else
		a[i]=t+'0'-0;
	temp=n/16;
	while(temp!=0)
	{
		i++;
		t=temp%16;
		if(t>9)
			a[i]=t+'a'-10;
		else
			a[i]=t+'0'-0;
		temp=temp/16;
	}
	for(j=i;j>=0;j--)
	{
		printf("%c",a[j]);
	}
return 0;}


int sixteen_ten()
{   
	system("cls");
	int n=0,i,t;
	char a[16];
	puts("请输入十六进制的数:");
	scanf("%s",a);
	t=strlen(a);
	for(i=0;i<=strlen(a)-1;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{	n+=(a[i]-48)*pow(16,t-1);

		}
		else
		{
			n+=(a[i]-87)*pow(16,t-1);
	
		}
		t--;
	}
	printf("\n%s的十进制数为:%d\n",a,n);
	return 0;
}


int main()
{  
loop:
	start();
	 int choice,j;//选择进制转换
	 double num;
	 printf("选择进制转换:");
	 scanf("%d",&choice);


	 switch(choice)
	 {
	 case 1:
	 system("cls");
     printf("输入你要转换的数字:");
	 scanf("%lf",&num);
  	 printf("请输入小数点后保留位数:");
     scanf("%d",&countw);
	 ten_two1(num);
	 ten_two2(num);
	 printf("\n按1返回，2退出\n");
	 scanf("%d",&j);
	 if(j==1)
	 {system("cls");
		 goto loop;
	 }
	 break;
	 case 2:
		 two_ten();
		 printf("\n按1返回，2退出\n");
		 scanf("%d",&j);
		 if(j==1)
		 {system("cls");
		 goto loop;
		 }
		 break;
	case 3:
		 ten_eight();
		 printf("\n按1返回，2退出\n");
		 scanf("%d",&j);
		 if(j==1)
		 {system("cls");
		 goto loop;
		 }
		 break;
	case 4:
		system("cls");
		 eight_ten();
         printf("\n按1返回，2退出\n");
		 scanf("%d",&j);
		 if(j==1)
		 {system("cls");
		 goto loop;
		 }
		 break;
	case 5:
		ten_sixteen();
		printf("\n按1返回，2退出\n");
		scanf("%d",&j);
		if(j==1)
		 {system("cls");
		 goto loop;
		 }
		 break;
	case 6:
		sixteen_ten();
      	printf("\n按1返回，2退出\n");
		scanf("%d",&j);
		if(j==1)
		 {system("cls");
		 goto loop;
		 }
		 break;


	 }



return 0;
}
