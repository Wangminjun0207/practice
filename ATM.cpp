#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/************************************************
这里定义了一些全局变量，作法没有问题，但一般情况下命名规则不是这样的，全局变量需要用g_开头的命名方式。
比如，int money=1000;应该是int g_nMoney = 1000;
原因就是让人知道，这是个全局变量,而为什么在Money前面加n呢？
是因为在一般的命名规范里，整型变量用n或者i开始，长整型用l开始，指针用p开始，字符用b开始，而字符串用str开始，数组是用Arr开头的，养成这个习惯 

*************************************************/
int money=1000;    //g_nMoney
char b[6]={'1','2','3','4','5','6'};  //g_bArr
int time=0;        //g_iTime或者g_nTime. 

/************************************************
这里定义的全局函数，需要声明，做法也没有问题，不过不应该用这么多的void类型，记住，void是万不利己不要用，你一般用int类型，在函数执行成功后， return 0,不成功return一个值，比如-1，-10001，-10002等等，这样就知道是哪里出错了。
比如写login
int UserLogin()
{
     int nErrorCode = -1;
	 if （用户名不存在）
	 {
	   nErrorCode = -10001;
	 }
	 elseif(密码错误)
	 {
	    nErrorCode = -10002;
	 }
	 else
	 {
	   nErrorCode = 0;
     }     
     return nErrorCode;	  
}


所以下面的函数都用int改过来吧，另外，函数名不要用拼音，不要用拼音，不要用拼音！！！！！ 
*************************************************/

 

void login();
void jiemian();
void savemoney();
void getmoney();
void query();
void Return();
void login()
{
	char a[20];
	int i=0,n=1,k;
	printf("\n\t\t\t\t\t\t欢迎使用ATM自动存取款机\n");
	printf("\n\t\t\t\t\t\t welcome to our bank！\n");
	printf("\n\t\t\t\t\t\t  请输入您的账户密码：\n");
	for(n=1;n<=3;n++)
	{
		loop:
		while((a[i]=getch())!=13)
		{
			i=i+1;
			printf("*");
		}
		for(k=0;k<6;k++)
			if(a[k]!=b[k])
				break;
			if(k==6)
			{
				printf("\n密码正确，请继续！\n");
				jiemian();
			}
			else
				{
					system("cls");
					printf("\n密码错误，请重新输入！\n");
					time++;
					if(time==3)
					{
						system("cls");
						printf("\n\n\t\t\t\t\t由于密码错误次数过多，您的账户已锁定！\n\n\n\n\n\n");
						system("pause");
						Return();
					} 
					i=0;
					goto loop; 
				} 
			exit(1);
	}
}
void jiemian()
{
	int selectkey;
	system("cls");
	while(1)
	{
		printf("\n");
		puts("\t\t\t\t\t\t=======================");
		puts("\t\t\t\t\t\t| 1.查询功能          |");
		puts("\t\t\t\t\t\t| 2.取款功能          |");
		puts("\t\t\t\t\t\t| 3.存款功能          |");
		puts("\t\t\t\t\t\t| 4.退出功能          |");
		puts("\t\t\t\t\t\t=======================");
		printf("\n\t\t\t\t\t\t您好，请选择您需要的服务！\n");
		scanf("%d",&selectkey);
		switch(selectkey)
		{
		case 1:printf("\t\t\t\t\t\t\n查询功能\n");query();break;
		case 2:printf("\t\t\t\t\t\t\n取款功能\n");getmoney();break;
		case 3:printf("\t\t\t\t\t\t\n存款功能\n");savemoney();break;
		case 4:printf("\t\t\t\t\t\t\n退出功能\n");Return();break;
		}
	}
}
void query()
{
	system("cls");
	printf("\n\t\t\t\t\t\t您的账户余额为%d\n",money);
	system("pause");
	return;
}
void getmoney()
{
	system("cls");
	int m;
	loop:
	printf("\n\t\t\t\t\t\t请输入要取的金额：");
	scanf("%d",&m);
	if(m<=money)
	{
		money=money-m;
		printf("\t\t\t\t\t\t您的账户余额为：%d\n",money);
	}
	else
	{
		printf("\t\t\t\t\t\t您的账户余额不足，请重新输入!\n");
		goto loop;
	}
	return;
}
void savemoney()
{
	system("cls");
	int m;
	printf("\n\t\t\t\t\t\t请输入您要存入的金额：");
	scanf("%d",&m);
	money=money+m;
	printf("\t\t\t\t\t\t您的账户余额为：%d\n",money);
	return;
}
void Return()
{
	system("cls");
	puts("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t=======================" );
	puts("\t\t\t\t\t\t| 感谢您的使用，再见! |");
	puts("\t\t\t\t\t\t=======================\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(1);
}
int main()
{
	login();
}

