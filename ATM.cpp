#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
int money=1000;
char b[6]={'1','2','3','4','5','6'};
int time=0;
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

