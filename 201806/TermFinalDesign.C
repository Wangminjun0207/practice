#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <bios.h>
#define Esc    27
#define Enter  13
#define Up     0x4800
#define Down   0x5000

typedef union
{
	int word;
	char byte;
}keycode;

/*键盘信息获取函数*/ 
int get_key()
{
	keycode key;
	key.word = bioskey(0);
	return key.byte ? key.byte : key.word;
}

/*退出界面*/ 
void Return()
{
	int l;
	window(1,1,80,25);
	textbackground(LIGHTGRAY);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	textcolor(YELLOW);
	clrscr();
	
	/*绘制对话框边框的横线*/
	for(l=1;l<=40;l++)
	{
		gotoxy(l,1);
		putch(205);
		gotoxy(l,6);
		putch(205);
	}
	
	/*绘制对话框边框的竖线*/
	for(l=1;l<=6;l++)
	{
		gotoxy(1,l);
		putch(186);
		gotoxy(40,l);
		putch(186);
	}
	
	/*绘制对话框边框的四角*/
	gotoxy(1,1);
	putch(201);
	gotoxy(1,6);
	putch(200);
	gotoxy(40,1);
	putch(187);
	gotoxy(40,6);
	putch(188);
	gotoxy(4,2);
	
	/*输出提示信息*/
	gotoxy(4,3);
	cprintf("Thank you for useing it, goodbye!"); 
}

/*用于显示一个菜单条*/ 
void DipItem(int row, int text_color, int back_color, char *menu_item)
/*参数说明：row,该菜单子项的行位置，text_color,菜单子项的文字颜色；
  			back_color,菜单子项的背景色；menu_item,菜单项文字*/
{
	gotoxy(2,row);
	textbackground(back_color);
	textcolor(text_color);
	cputs(menu_item);
}

/*创建一个弹出式对话框，显示主菜单*/
void Dialog(int x0,int y0,int iWidth,int iRow,char *sTitle,char *information[])
{
	int i, len;
	
	/*绘制对话框阴影*/ 
	window(x0+1, y0+1, x0+iWidth+1, y0+iRow+1);
	textbackground(BLACK);
	clrscr();
	
	/*绘制对话框*/
	window(x0, y0, x0+iWidth, y0+iRow);
	textbackground(BLUE);
	clrscr();
	
	/*绘制对话框边框的四角*/
	textcolor(LIGHTGRAY);
	clrscr();
	gotoxy(1,1);
	putch(218);
	gotoxy(iWidth,1);
	putch(191);
	gotoxy(1,iRow+1);
	putch(192);
	gotoxy(iWidth,iRow+1);
	putch(217);
	
	/*绘制对话框边框的横线*/
	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,1);
		cprintf("%c",196);
		gotoxy(i,iRow+1);
		cprintf("%c",196);
	}
	
	/*绘制对话框边框的竖线*/
	for(i=2;i<=iRow;i++)
	{
		gotoxy(1,i);
		putch(179);
		gotoxy(iWidth,i);
		putch(179);
	}

	/*绘制对话框边框的分割线*/
	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,3);
		putch(205);
	}

	/*绘制对话框边框的交点*/
	gotoxy(1,3);
	putch(198);
	gotoxy(iWidth,3);
	putch(181);

	/*居中显示标题*/
	textcolor(BLACK);
	len = strlen(sTitle);
	gotoxy((iWidth-len)/2,2);
	cprintf("%s",sTitle);
	
	/*显示菜单条*/
	for(i=0;information[i];i++)
	{
		gotoxy(2,4+i);
		cprintf("%s",*(information+i));
	}
	
	/*光标回到右下角*/
	gotoxy(iWidth+1,iRow+1);
}

/*按Enter键时菜单子项突出显示*/
void print(int i)
{
	if(i==4)
		DipItem(4,YELLOW,8,"1.booking         ");
	if(i==5)
		DipItem(5,YELLOW,8,"2.refund          ");
	if(i==6)
		DipItem(6,YELLOW,8,"3.endorse         ");
	if(i==7)
		DipItem(7,YELLOW,8,"4.query           ");
	if(i==8)
		DipItem(8,YELLOW,8,"5.ticket          ");
}

int main()
{
	/*初始化主菜单标题和菜单子项内容*/
	char title[100] = "** FUNCTION **";
	char *information[6] = {"1.booking","2.refund",
				"3.endorse","4.query","5.ticket"};
	int key;
	int i=0;
	int j;
	int k;
	int l;
	int n;
	int flag;
	FILE *fp;
	char *buf1,*buf2;
	char temp[10];
	char number[10];
	int count;
	long long g_nNum = 201806001;
	char a[20];
	char origin[10];
	char destination[10];
	/*初始化登录密码*/
	char g_bArr[6]={'1','2','3','4','5','6'}; 
	int g_nTime=0;/*记录输入密码次数*/
	
	/*存储购票记录信息*/
	struct Ticket1
	{
		char number[10];
		char origin[10];
		char destination[10];
		char airline[20];
		int  count;
		int unitprice;
		int totalprice;
	}t1[10];

	/*存储余票信息*/
	struct Ticket2
	{
		char origin[10];
		char destination[10];
		char airline[20];
		int count;
		int unitprice;
	}t2[10];
	
	/*绘制登录界面对话框窗口*/
	for(j=0;j<10;j++)
	t1[j].count = 0;
	textbackground(LIGHTGRAY);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	textcolor(YELLOW);
	clrscr();
	
	/*绘制对话框边框的横线*/
	for(l=1;l<=40;l++)
	{
		gotoxy(l,1);
		putch(205);
		gotoxy(l,6);
		putch(205);
	}
	
	/*绘制对话框边框的竖线*/
	for(l=1;l<=6;l++)
	{
		gotoxy(1,l);
		putch(186);
		gotoxy(40,l);
		putch(186);
	}
	
	/*绘制对话框边框的四角*/
	gotoxy(1,1);
	putch(201);
	gotoxy(1,6);
	putch(200);
	gotoxy(40,1);
	putch(187);
	gotoxy(40,6);
	putch(188);
	gotoxy(4,2);
	
	/*进行账号登录*/
	cprintf("Please enter your account password!");
	for(n=1;n<=3;n++)
	{
		loop:
		gotoxy(i+4,3);
		
		/*输入密码，屏幕显示*******/
		while((a[i]=getch())!=13)
		{
			i=i+1;
			cprintf("*");
			gotoxy(i+4,3);
		}
		
		/*判断密码正误，错误时退出*/
		for(k=0;k<6;k++)
			if(a[k]!=g_bArr[k])
				break;
		
		/*如果密码正确，程序继续执行*/
		if(k==6)
		{
			gotoxy(4,4);
			cprintf("Password correct,please continue!");
			getch();
			break;
		}
		/*如果密码错误，重新输入密码*/
		else
		{
			gotoxy(4,4);
			printf("Password error, please re-enter.");
			getch();
			gotoxy(4,4);
			cprintf("                                ");
			gotoxy(4,3);
			cprintf("                 ");
			g_nTime++;
			/*密码输入三次以后，退出程序*/
			if(g_nTime==3)
			{
				gotoxy(4,2);
				cprintf("Due to too many password errors,   ");
				gotoxy(4,3);
				cprintf("your account has been locked!      ");
				gotoxy(4,4);
				cprintf("Thank you for you use!             ");
				getch();
				exit(1);
			}
			i=0;
			goto loop;
		}
	}

	/*从文件读入Ticket2数组*/
	if((fp = fopen("ticket2_file.txt","r"))==NULL)
	/* 打开文件并且进行判断，是否打开*/
	{
		exit(0);
	}
	for(i=0;i<10;i++)
		fscanf(fp,"%s%s%s%d%d",&t2[i].origin,&t2[i].destination,&t2[i].airline,&t2[i].count,&t2[i].unitprice);
	fclose(fp);

	/*从文件读入Ticket1数组*/
	if((fp = fopen("ticket1_file.txt","r"))==NULL)
	/* 打开文件并且进行判断，是否打开*/
	{
		exit(0);
	}
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%s%s%s%s%d%d%d",&t1[i].number,&t1[i].origin,&t1[i].destination,&t1[i].airline,&t1[i].count,&t1[i].unitprice,&t1[i].totalprice);
		if(t1[i].count!=0)
			g_nNum = g_nNum + 1;
	}
	fclose(fp);

	/*登录成功，进入系统操作界面*/
	window(1,1,80,25);
	textbackground(LIGHTGRAY);
	clrscr();
	Dialog(10,10,20,9,title,information);
	buf1 = (char *)malloc(80*25*2);
	buf2 = (char *)malloc(80*25*2);
	gettext(1,1,80,25,buf1);
	i=4;
	print(i);
	
	/*获取一个按键信息*/
	key = get_key();
	puttext(1,1,80,25,buf1);
	
	/*当按Esc键时退出程序*/
	while(key != Esc)
	{
		switch(key)
		{
			/*按Up键菜单向下移动*/
			case Up:if(i==4)
					{
						DipItem(4,YELLOW,8,"1.booking         ");
						break;
					}
					else
					i--;
					print(i);
					break;
			
			/*按Down键菜单向上移动*/
			case Down:if(i==8)
					  {
						  DipItem(8,YELLOW,8,"5.ticket          ");
						  break;
					  }
					  else
						i++;
					  print(i);
					  break;
			
			/*按Enter进入菜单功能*/
			case Enter:print(i);
					   
					   /*绘制菜单功能对话框*/
					   gettext(1,1,80,25,buf2);
					   window(10,5,70,20);
					   textbackground(BLUE);
					   textcolor(YELLOW);
					   clrscr();
					   
					   /*绘制对话框边框横线*/
					   for(k=2;k<60;k++)
					   {
							gotoxy(k,1);
							putch(205);
							gotoxy(k,3);
							putch(205);
							gotoxy(k,16);
							putch(205);
					   }
					   
					   /*绘制对话框边框竖线*/
					   for(k=1;k<=16;k++)
					   {
							gotoxy(2,k);
							putch(186);
							gotoxy(60,k);
							putch(186);
					   }
					   
					   /*绘制对话框边框四角*/
					   gotoxy(2,1);
					   putch(201);
					   gotoxy(60,1);
					   putch(187);
					   gotoxy(2,16);
					   putch(200);
					   gotoxy(60,16);
					   putch(188);
					   
					   /*绘制对话框边框交点*/
					   gotoxy(2,3);
					   putch(204);
					   gotoxy(60,3);
					   putch(185);

					   switch(i)
					   {
					   		/*执行预定机票功能*/
							case 4: l = strlen("***** booking *****");
									gotoxy(30-l/2,2);
									cprintf("***** booking *****");
									for(j=0;j<10;j++)
									{
										if(t1[j].count == 0)
											break;
									}
									gotoxy(4,5);
									/*输入出发地和目的地查找机票信息*/
									cprintf("please input origin:");
									scanf("%s",&t1[j].origin);
									gotoxy(4,6);
									cprintf("please input destination:");
									scanf("%s",&t1[j].destination);
									flag = 0;
									for(k=0;k<10;k++)
									{
										/*查到信息输出*/
										if(strcmp(t1[j].origin,t2[k].origin)==0 &&
											strcmp(t1[j].destination,t2[k].destination)==0)
										 {
											gotoxy(4,8);
											cprintf("The query results are as following:\r\n");
											gotoxy(4,9);
											cprintf("%12s%12s%15s%6d%8d\r\n\n",t2[k].origin,t2[k].destination,
										            t2[k].airline,t2[k].count,t2[k].unitprice);
											flag = 1;
											break;
										}
								   }
								   
								   /*查不到信息退出订票*/
								   if(flag == 0)
								   {
										gotoxy(4,8);
										cprintf("Not any infromation...");
										break;
								   }
								   gotoxy(4,11);
								   
								   /*查到余票，输入订票数量*/
								   printf("please input count:");
								   scanf("%d",&t1[j].count);
								   n = 0;
								   
								   /*输入订票数大于余票数，执行重新输入*/
								   while(t1[j].count>t2[k].count)
								   {
										n++;
										gotoxy(4,11+n);
										cprintf("please input count again:");
										scanf("%d",&t1[j].count);
								   }
								   gotoxy(4,12+n);
								   
								   /*预定成功，输出提示信息*/
								   if(t1[j].count>0)
										cprintf("Reservation success, press any key return ...");
								   /*预定失败，输出提示信息*/
								   else
								   {
										cprintf("Reservation failure, press any key return ...");
										break;
								   }
								   
								   /*预定成功，记录订票信息，更新余票信息*/
								   t2[k].count = t2[k].count - t1[j].count;
								   g_nNum=g_nNum+1;
								   itoa(g_nNum,temp,10);
								   strcpy(t1[j].number,temp);
								   strcpy(t1[j].airline,t2[k].airline);
								   t1[j].unitprice = t2[k].unitprice;
								   t1[j].totalprice = t1[j].count*t2[k].unitprice;
								   break;
								   
							/*执行退机票功能*/
							case 5: l = strlen("***** refund *****");
									gotoxy(30-l/2,2);
									cprintf("***** REFUND *****");
									flag = 0;
									n = 0;
									
									/*查询订单信息*/
									for(j=0;j<10;j++)
									{
										if(t1[j].count!=0)
										{
											flag = 1;
											break;
										}
									}
									gotoxy(4,4);
									
									/*如果有订单，输出订单信息*/
									if(flag==1)
									{
										cprintf("You have the following order:");
										for(j=0;j<10;j++)
										{
											if(t1[j].count == 0)
											{
												continue;
											}
											else
											{
												n++;
												gotoxy(4,n+4);
												cprintf("%5s%10s%10s%12s%4d%6d%8d",t1[j].number,t1[j].origin,t1[j].destination,
												t1[j].airline,t1[j].count,t1[j].unitprice,t1[j].totalprice);
											}
										}
										
										/*选择要退订的机票*/
										flag = 0;
										
										/*订单号输入错误时重新输入*/ 
										do{
											gotoxy(4,6+n);
											cprintf("please input number that you need refund:");
											scanf("%s",&number);
											for(j=0;j<10;j++)
											{
												if(strcmp(t1[j].number,number)==0)
												{
													flag = 1;
													break;
												}
											}
											if(flag==1)
												break;
											n++;
										}while(flag==0);
										gotoxy(4,7+n);
										
										/*输入退票的数量*/
										cprintf("please input count that you need refund:");
										scanf("%d",&count);
										
										/*如果输入的退票数量大于订单数量，从新输入*/
										while(count>t1[j].count)
										{
											n++;
											gotoxy(4,n+7);
											cprintf("please input count that you refund again:");
											scanf("%d",&count);
										}
										
										strcpy(origin,t1[j].origin);
										strcpy(destination,t1[j].destination);
										
										/*更新订单和余票信息*/
										t1[j].count = t1[j].count - count;
										for(k=0;k<10;k++)
										{
											if(strcmp(t2[k].origin,origin)==0 &&
												strcmp(t2[k].destination,destination)==0)
											 {
												 t2[k].count = t2[k].count + count;
												 break;
											}
										}
										gotoxy(4,8+n);
										
										/*退票成功，输出提示信息*/
										cprintf("Refund success, press any key return ...");
									}
									
									/*如果没有订单，输出提示信息*/
									else
										cprintf("Not have any information...");
									break;
									
							/*执行改签机票功能*/
							case 6: l = strlen("***** endorse *****");
									gotoxy(30-l/2,2);
									cprintf("***** ENDORSE *****");
									flag = 0;
									n = 0;
									
									/*查询订单信息*/
									for(j=0;j<10;j++)
									{
										if(t1[j].count!=0)
										{
											flag = 1;
											break;
										}
									}
									gotoxy(4,4);
									
									/*如果有订单，输出订单信息*/
									if(flag==1)
									{
										cprintf("You have the following order:");
										for(j=0;j<10;j++)
										{
											if(t1[j].count == 0)
											{
												continue;
											}
											else
											{
												n++;
												gotoxy(4,n+4);
												cprintf("%5s%10s%10s%12s%4d%6d%8d",t1[j].number,t1[j].origin,t1[j].destination,
												t1[j].airline,t1[j].count,t1[j].unitprice,t1[j].totalprice);
											}
										}
										flag = 0;
										
										/*选择改签的订单*/
										do
										{
											gotoxy(4,6+n);
											cprintf("please input number that you need endrose:");
											scanf("%s",&number);
											for(j=0;j<10;j++)
											{
												if(strcmp(t1[j].number,number)==0)
												{
													strcpy(origin,t1[j].origin);
													strcpy(destination,t1[j].destination);
													flag=1;
													break;
												}
											}
											n++;
											gotoxy(4,6+n);
											if(flag==0)
											{
												cprintf("select failure, press ang key continue...");
												getch();
											}
										}while(flag == 0);
										
										/*更新订单和余票信息*/
										for(k=0;k<10;k++)
										{
											if(strcmp(t2[k].origin,origin)==0 &&
												 strcmp(t2[k].destination,destination)==0)
											{
												 t2[k].count = t2[k].count + t1[j].count;
												 t1[j].count = 0;
												 break;
											}
										}
										gotoxy(4,7+n);
										
										/*选择成功，输出提示信息*/
										cprintf("select success, press any key return ...");
										getch();

										for(j=0;j<10;j++)
										{
											if(t1[j].count == 0)
												break;
										}
										window(12,8,68,19);
										clrscr();
										gotoxy(2,1);
										
										/*输入改签后的出发地*/
										cprintf("please input origin:");
										scanf("%s",&t1[j].origin);
										gotoxy(2,2);
										
										/*输入改签后的目的地*/
										cprintf("please input destination:");
										scanf("%s",&t1[j].destination);
										flag = 0;
										
										/*查询机票，如果有余票，输出余票信息*/
										for(k=0;k<10;k++)
										{
											if(strcmp(t1[j].origin,t2[k].origin)==0 &&
												strcmp(t1[j].destination,t2[k].destination)==0)
											 {
												gotoxy(2,3);
												cprintf("The query results are as following:\r\n");
												gotoxy(2,4);
												cprintf("%12s%12s%15s%6d%8d\r\n\n",t2[k].origin,t2[k].destination,
												      t2[k].airline,t2[k].count,t2[k].unitprice);
												flag = 1;
												break;
											}
								 		}
								 		
								 		/*如果没有机票信息，输出提示信息*/
								   		if(flag == 0)
								  		{
											gotoxy(2,3);
											cprintf("Not any infromation...");
											break;
								   		}
								   		gotoxy(2,5);
								   		
								   		/*输入改签后的机票数量*/
								   		printf("please input count:");
								   		scanf("%d",&t1[j].count);
								   		
								   		/*如果输入的订单数量大于余票数量，重新输入*/
								   		while(t1[j].count>t2[k].count)
								   		{
											n++;
											gotoxy(2,5+n);
											cprintf("please input count again:");
											scanf("%d",&t1[j].count);
									    }
								   		gotoxy(2,6+n);
								   		
								   		/*改签成功，输出提示信息*/
								  		if(t1[j].count>0)
											cprintf("Endrose success, press any key return ...");
										/*改签失败，输出提示信息*/
								   		else
											cprintf("Endrose failure, press any key return ...");
											
										/*更新订单和余票数量*/
								   		t2[k].count = t2[k].count - t1[j].count;
								   		itoa(g_nNum++,temp,10);
								   		strcpy(t1[j].number,temp);
								   		strcpy(t1[j].airline,t2[k].airline);
								   		t1[j].unitprice = t2[k].unitprice;
								   		t1[j].totalprice = t1[j].count*t2[k].unitprice;
									}
									
									/*如果没有订单，输出提示信息*/
									else
										cprintf("Not have any information...");
									break;
							/*执行查询订单功能*/
							
							case 7: l = strlen("***** query *****");
									gotoxy(30-l/2,2);
									cprintf("***** QUERY *****");
									n = 0;
									
									/*如果有订单，输出订单信息*/
								   	for(j=0;j<10;j++)
								   	{
										if(t1[j].count == 0)
										{
											continue;
										}
										else
										{
											gotoxy(4,n+4);
											cprintf("%5s%10s%10s%12s%4d%6d%8d",t1[j].number,t1[j].origin,t1[j].destination,
												t1[j].airline,t1[j].count,t1[j].unitprice,t1[j].totalprice);
											n++;
										}
								   	}
								   	
								   	/*如果没订单，输出提示信息*/
								   	if(n==0)
								   	{
										gotoxy(4,4);
										cprintf("Not ang information...");
								   	}
								   	break;
								   	
							/*执行查询余票功能*/
							case 8: l = strlen("***** ticket *****");
									gotoxy(30-l/2,2);
									cprintf("***** TICKET *****");
									gotoxy(4,4);
									
									/*输出余票信息*/
							       	cprintf("   origin    destination    airline   count   unit price");
							       	for(j=0;j<10;j++)
							       	{
										gotoxy(4,6+j);
										cprintf("%10s%12s%15s%5d%10d\r\n",t2[j].origin,t2[j].destination,
										     	 t2[j].airline,t2[j].count,t2[j].unitprice);
							       	}
							       	
							       	/*光标回到右下角*/
							       	gotoxy(59,15);
							       	break;
							default:break;
					   }
					   getch();
					   puttext(1,1,80,25,buf2);
					   
					   /*移动光标到合适位置*/
					   if(i==6)
							gotoxy(19,11);
					   else
							gotoxy(19,5+i);
					   break;
			default:break;
		}
		
		/*获取一个按键信息*/
		key = get_key();
		
		/*退出子功能，回到主菜单*/
		window(10,10,30,18);
		puttext(1,1,80,25,buf1);
	}

	/*余票信息写入文件*/
	if((fp = fopen("ticket2_file.txt","w"))==NULL) 
	/* 打开文件并且进行判断，是否打开*/
	{
		exit(0);
	}
	for(i=0;i<10;i++)
	{
		fprintf(fp,"%s %s %s %d %d\n",t2[i].origin,t2[i].destination,t2[i].airline,t2[i].count,t2[i].unitprice);
	}
	fclose(fp);

	/*订单信息写入文件*/
	if((fp = fopen("ticket1_file.txt","w"))==NULL) 
	/*打开文件并且进行判断，是否打开*/
	{
		exit(0);
	}
	for(i=0;i<10;i++)
	{       if(t1[i].count!=0)
		fprintf(fp,"%s %s %s %s %d %d %d\n",t1[i].number,t1[i].origin,t1[i].destination,t1[i].airline,t1[i].count,t1[i].unitprice,t1[i].totalprice);
	}
	fclose(fp);
	
	/*显示退出界面信息*/
	Return();
	getch();
	return 0;
}
