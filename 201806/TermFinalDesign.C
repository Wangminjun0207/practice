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

/*������Ϣ��ȡ����*/ 
int get_key()
{
	keycode key;
	key.word = bioskey(0);
	return key.byte ? key.byte : key.word;
}

/*�˳�����*/ 
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
	
	/*���ƶԻ���߿�ĺ���*/
	for(l=1;l<=40;l++)
	{
		gotoxy(l,1);
		putch(205);
		gotoxy(l,6);
		putch(205);
	}
	
	/*���ƶԻ���߿������*/
	for(l=1;l<=6;l++)
	{
		gotoxy(1,l);
		putch(186);
		gotoxy(40,l);
		putch(186);
	}
	
	/*���ƶԻ���߿���Ľ�*/
	gotoxy(1,1);
	putch(201);
	gotoxy(1,6);
	putch(200);
	gotoxy(40,1);
	putch(187);
	gotoxy(40,6);
	putch(188);
	gotoxy(4,2);
	
	/*�����ʾ��Ϣ*/
	gotoxy(4,3);
	cprintf("Thank you for useing it, goodbye!"); 
}

/*������ʾһ���˵���*/ 
void DipItem(int row, int text_color, int back_color, char *menu_item)
/*����˵����row,�ò˵��������λ�ã�text_color,�˵������������ɫ��
  			back_color,�˵�����ı���ɫ��menu_item,�˵�������*/
{
	gotoxy(2,row);
	textbackground(back_color);
	textcolor(text_color);
	cputs(menu_item);
}

/*����һ������ʽ�Ի�����ʾ���˵�*/
void Dialog(int x0,int y0,int iWidth,int iRow,char *sTitle,char *information[])
{
	int i, len;
	
	/*���ƶԻ�����Ӱ*/ 
	window(x0+1, y0+1, x0+iWidth+1, y0+iRow+1);
	textbackground(BLACK);
	clrscr();
	
	/*���ƶԻ���*/
	window(x0, y0, x0+iWidth, y0+iRow);
	textbackground(BLUE);
	clrscr();
	
	/*���ƶԻ���߿���Ľ�*/
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
	
	/*���ƶԻ���߿�ĺ���*/
	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,1);
		cprintf("%c",196);
		gotoxy(i,iRow+1);
		cprintf("%c",196);
	}
	
	/*���ƶԻ���߿������*/
	for(i=2;i<=iRow;i++)
	{
		gotoxy(1,i);
		putch(179);
		gotoxy(iWidth,i);
		putch(179);
	}

	/*���ƶԻ���߿�ķָ���*/
	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,3);
		putch(205);
	}

	/*���ƶԻ���߿�Ľ���*/
	gotoxy(1,3);
	putch(198);
	gotoxy(iWidth,3);
	putch(181);

	/*������ʾ����*/
	textcolor(BLACK);
	len = strlen(sTitle);
	gotoxy((iWidth-len)/2,2);
	cprintf("%s",sTitle);
	
	/*��ʾ�˵���*/
	for(i=0;information[i];i++)
	{
		gotoxy(2,4+i);
		cprintf("%s",*(information+i));
	}
	
	/*���ص����½�*/
	gotoxy(iWidth+1,iRow+1);
}

/*��Enter��ʱ�˵�����ͻ����ʾ*/
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
	/*��ʼ�����˵�����Ͳ˵���������*/
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
	/*��ʼ����¼����*/
	char g_bArr[6]={'1','2','3','4','5','6'}; 
	int g_nTime=0;/*��¼�����������*/
	
	/*�洢��Ʊ��¼��Ϣ*/
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

	/*�洢��Ʊ��Ϣ*/
	struct Ticket2
	{
		char origin[10];
		char destination[10];
		char airline[20];
		int count;
		int unitprice;
	}t2[10];
	
	/*���Ƶ�¼����Ի��򴰿�*/
	for(j=0;j<10;j++)
	t1[j].count = 0;
	textbackground(LIGHTGRAY);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	textcolor(YELLOW);
	clrscr();
	
	/*���ƶԻ���߿�ĺ���*/
	for(l=1;l<=40;l++)
	{
		gotoxy(l,1);
		putch(205);
		gotoxy(l,6);
		putch(205);
	}
	
	/*���ƶԻ���߿������*/
	for(l=1;l<=6;l++)
	{
		gotoxy(1,l);
		putch(186);
		gotoxy(40,l);
		putch(186);
	}
	
	/*���ƶԻ���߿���Ľ�*/
	gotoxy(1,1);
	putch(201);
	gotoxy(1,6);
	putch(200);
	gotoxy(40,1);
	putch(187);
	gotoxy(40,6);
	putch(188);
	gotoxy(4,2);
	
	/*�����˺ŵ�¼*/
	cprintf("Please enter your account password!");
	for(n=1;n<=3;n++)
	{
		loop:
		gotoxy(i+4,3);
		
		/*�������룬��Ļ��ʾ*******/
		while((a[i]=getch())!=13)
		{
			i=i+1;
			cprintf("*");
			gotoxy(i+4,3);
		}
		
		/*�ж��������󣬴���ʱ�˳�*/
		for(k=0;k<6;k++)
			if(a[k]!=g_bArr[k])
				break;
		
		/*���������ȷ���������ִ��*/
		if(k==6)
		{
			gotoxy(4,4);
			cprintf("Password correct,please continue!");
			getch();
			break;
		}
		/*����������������������*/
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
			/*�������������Ժ��˳�����*/
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

	/*���ļ�����Ticket2����*/
	if((fp = fopen("ticket2_file.txt","r"))==NULL)
	/* ���ļ����ҽ����жϣ��Ƿ��*/
	{
		exit(0);
	}
	for(i=0;i<10;i++)
		fscanf(fp,"%s%s%s%d%d",&t2[i].origin,&t2[i].destination,&t2[i].airline,&t2[i].count,&t2[i].unitprice);
	fclose(fp);

	/*���ļ�����Ticket1����*/
	if((fp = fopen("ticket1_file.txt","r"))==NULL)
	/* ���ļ����ҽ����жϣ��Ƿ��*/
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

	/*��¼�ɹ�������ϵͳ��������*/
	window(1,1,80,25);
	textbackground(LIGHTGRAY);
	clrscr();
	Dialog(10,10,20,9,title,information);
	buf1 = (char *)malloc(80*25*2);
	buf2 = (char *)malloc(80*25*2);
	gettext(1,1,80,25,buf1);
	i=4;
	print(i);
	
	/*��ȡһ��������Ϣ*/
	key = get_key();
	puttext(1,1,80,25,buf1);
	
	/*����Esc��ʱ�˳�����*/
	while(key != Esc)
	{
		switch(key)
		{
			/*��Up���˵������ƶ�*/
			case Up:if(i==4)
					{
						DipItem(4,YELLOW,8,"1.booking         ");
						break;
					}
					else
					i--;
					print(i);
					break;
			
			/*��Down���˵������ƶ�*/
			case Down:if(i==8)
					  {
						  DipItem(8,YELLOW,8,"5.ticket          ");
						  break;
					  }
					  else
						i++;
					  print(i);
					  break;
			
			/*��Enter����˵�����*/
			case Enter:print(i);
					   
					   /*���Ʋ˵����ܶԻ���*/
					   gettext(1,1,80,25,buf2);
					   window(10,5,70,20);
					   textbackground(BLUE);
					   textcolor(YELLOW);
					   clrscr();
					   
					   /*���ƶԻ���߿����*/
					   for(k=2;k<60;k++)
					   {
							gotoxy(k,1);
							putch(205);
							gotoxy(k,3);
							putch(205);
							gotoxy(k,16);
							putch(205);
					   }
					   
					   /*���ƶԻ���߿�����*/
					   for(k=1;k<=16;k++)
					   {
							gotoxy(2,k);
							putch(186);
							gotoxy(60,k);
							putch(186);
					   }
					   
					   /*���ƶԻ���߿��Ľ�*/
					   gotoxy(2,1);
					   putch(201);
					   gotoxy(60,1);
					   putch(187);
					   gotoxy(2,16);
					   putch(200);
					   gotoxy(60,16);
					   putch(188);
					   
					   /*���ƶԻ���߿򽻵�*/
					   gotoxy(2,3);
					   putch(204);
					   gotoxy(60,3);
					   putch(185);

					   switch(i)
					   {
					   		/*ִ��Ԥ����Ʊ����*/
							case 4: l = strlen("***** booking *****");
									gotoxy(30-l/2,2);
									cprintf("***** booking *****");
									for(j=0;j<10;j++)
									{
										if(t1[j].count == 0)
											break;
									}
									gotoxy(4,5);
									/*��������غ�Ŀ�ĵز��һ�Ʊ��Ϣ*/
									cprintf("please input origin:");
									scanf("%s",&t1[j].origin);
									gotoxy(4,6);
									cprintf("please input destination:");
									scanf("%s",&t1[j].destination);
									flag = 0;
									for(k=0;k<10;k++)
									{
										/*�鵽��Ϣ���*/
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
								   
								   /*�鲻����Ϣ�˳���Ʊ*/
								   if(flag == 0)
								   {
										gotoxy(4,8);
										cprintf("Not any infromation...");
										break;
								   }
								   gotoxy(4,11);
								   
								   /*�鵽��Ʊ�����붩Ʊ����*/
								   printf("please input count:");
								   scanf("%d",&t1[j].count);
								   n = 0;
								   
								   /*���붩Ʊ��������Ʊ����ִ����������*/
								   while(t1[j].count>t2[k].count)
								   {
										n++;
										gotoxy(4,11+n);
										cprintf("please input count again:");
										scanf("%d",&t1[j].count);
								   }
								   gotoxy(4,12+n);
								   
								   /*Ԥ���ɹ��������ʾ��Ϣ*/
								   if(t1[j].count>0)
										cprintf("Reservation success, press any key return ...");
								   /*Ԥ��ʧ�ܣ������ʾ��Ϣ*/
								   else
								   {
										cprintf("Reservation failure, press any key return ...");
										break;
								   }
								   
								   /*Ԥ���ɹ�����¼��Ʊ��Ϣ��������Ʊ��Ϣ*/
								   t2[k].count = t2[k].count - t1[j].count;
								   g_nNum=g_nNum+1;
								   itoa(g_nNum,temp,10);
								   strcpy(t1[j].number,temp);
								   strcpy(t1[j].airline,t2[k].airline);
								   t1[j].unitprice = t2[k].unitprice;
								   t1[j].totalprice = t1[j].count*t2[k].unitprice;
								   break;
								   
							/*ִ���˻�Ʊ����*/
							case 5: l = strlen("***** refund *****");
									gotoxy(30-l/2,2);
									cprintf("***** REFUND *****");
									flag = 0;
									n = 0;
									
									/*��ѯ������Ϣ*/
									for(j=0;j<10;j++)
									{
										if(t1[j].count!=0)
										{
											flag = 1;
											break;
										}
									}
									gotoxy(4,4);
									
									/*����ж��������������Ϣ*/
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
										
										/*ѡ��Ҫ�˶��Ļ�Ʊ*/
										flag = 0;
										
										/*�������������ʱ��������*/ 
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
										
										/*������Ʊ������*/
										cprintf("please input count that you need refund:");
										scanf("%d",&count);
										
										/*����������Ʊ�������ڶ�����������������*/
										while(count>t1[j].count)
										{
											n++;
											gotoxy(4,n+7);
											cprintf("please input count that you refund again:");
											scanf("%d",&count);
										}
										
										strcpy(origin,t1[j].origin);
										strcpy(destination,t1[j].destination);
										
										/*���¶�������Ʊ��Ϣ*/
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
										
										/*��Ʊ�ɹ��������ʾ��Ϣ*/
										cprintf("Refund success, press any key return ...");
									}
									
									/*���û�ж����������ʾ��Ϣ*/
									else
										cprintf("Not have any information...");
									break;
									
							/*ִ�и�ǩ��Ʊ����*/
							case 6: l = strlen("***** endorse *****");
									gotoxy(30-l/2,2);
									cprintf("***** ENDORSE *****");
									flag = 0;
									n = 0;
									
									/*��ѯ������Ϣ*/
									for(j=0;j<10;j++)
									{
										if(t1[j].count!=0)
										{
											flag = 1;
											break;
										}
									}
									gotoxy(4,4);
									
									/*����ж��������������Ϣ*/
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
										
										/*ѡ���ǩ�Ķ���*/
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
										
										/*���¶�������Ʊ��Ϣ*/
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
										
										/*ѡ��ɹ��������ʾ��Ϣ*/
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
										
										/*�����ǩ��ĳ�����*/
										cprintf("please input origin:");
										scanf("%s",&t1[j].origin);
										gotoxy(2,2);
										
										/*�����ǩ���Ŀ�ĵ�*/
										cprintf("please input destination:");
										scanf("%s",&t1[j].destination);
										flag = 0;
										
										/*��ѯ��Ʊ���������Ʊ�������Ʊ��Ϣ*/
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
								 		
								 		/*���û�л�Ʊ��Ϣ�������ʾ��Ϣ*/
								   		if(flag == 0)
								  		{
											gotoxy(2,3);
											cprintf("Not any infromation...");
											break;
								   		}
								   		gotoxy(2,5);
								   		
								   		/*�����ǩ��Ļ�Ʊ����*/
								   		printf("please input count:");
								   		scanf("%d",&t1[j].count);
								   		
								   		/*�������Ķ�������������Ʊ��������������*/
								   		while(t1[j].count>t2[k].count)
								   		{
											n++;
											gotoxy(2,5+n);
											cprintf("please input count again:");
											scanf("%d",&t1[j].count);
									    }
								   		gotoxy(2,6+n);
								   		
								   		/*��ǩ�ɹ��������ʾ��Ϣ*/
								  		if(t1[j].count>0)
											cprintf("Endrose success, press any key return ...");
										/*��ǩʧ�ܣ������ʾ��Ϣ*/
								   		else
											cprintf("Endrose failure, press any key return ...");
											
										/*���¶�������Ʊ����*/
								   		t2[k].count = t2[k].count - t1[j].count;
								   		itoa(g_nNum++,temp,10);
								   		strcpy(t1[j].number,temp);
								   		strcpy(t1[j].airline,t2[k].airline);
								   		t1[j].unitprice = t2[k].unitprice;
								   		t1[j].totalprice = t1[j].count*t2[k].unitprice;
									}
									
									/*���û�ж����������ʾ��Ϣ*/
									else
										cprintf("Not have any information...");
									break;
							/*ִ�в�ѯ��������*/
							
							case 7: l = strlen("***** query *****");
									gotoxy(30-l/2,2);
									cprintf("***** QUERY *****");
									n = 0;
									
									/*����ж��������������Ϣ*/
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
								   	
								   	/*���û�����������ʾ��Ϣ*/
								   	if(n==0)
								   	{
										gotoxy(4,4);
										cprintf("Not ang information...");
								   	}
								   	break;
								   	
							/*ִ�в�ѯ��Ʊ����*/
							case 8: l = strlen("***** ticket *****");
									gotoxy(30-l/2,2);
									cprintf("***** TICKET *****");
									gotoxy(4,4);
									
									/*�����Ʊ��Ϣ*/
							       	cprintf("   origin    destination    airline   count   unit price");
							       	for(j=0;j<10;j++)
							       	{
										gotoxy(4,6+j);
										cprintf("%10s%12s%15s%5d%10d\r\n",t2[j].origin,t2[j].destination,
										     	 t2[j].airline,t2[j].count,t2[j].unitprice);
							       	}
							       	
							       	/*���ص����½�*/
							       	gotoxy(59,15);
							       	break;
							default:break;
					   }
					   getch();
					   puttext(1,1,80,25,buf2);
					   
					   /*�ƶ���굽����λ��*/
					   if(i==6)
							gotoxy(19,11);
					   else
							gotoxy(19,5+i);
					   break;
			default:break;
		}
		
		/*��ȡһ��������Ϣ*/
		key = get_key();
		
		/*�˳��ӹ��ܣ��ص����˵�*/
		window(10,10,30,18);
		puttext(1,1,80,25,buf1);
	}

	/*��Ʊ��Ϣд���ļ�*/
	if((fp = fopen("ticket2_file.txt","w"))==NULL) 
	/* ���ļ����ҽ����жϣ��Ƿ��*/
	{
		exit(0);
	}
	for(i=0;i<10;i++)
	{
		fprintf(fp,"%s %s %s %d %d\n",t2[i].origin,t2[i].destination,t2[i].airline,t2[i].count,t2[i].unitprice);
	}
	fclose(fp);

	/*������Ϣд���ļ�*/
	if((fp = fopen("ticket1_file.txt","w"))==NULL) 
	/*���ļ����ҽ����жϣ��Ƿ��*/
	{
		exit(0);
	}
	for(i=0;i<10;i++)
	{       if(t1[i].count!=0)
		fprintf(fp,"%s %s %s %s %d %d %d\n",t1[i].number,t1[i].origin,t1[i].destination,t1[i].airline,t1[i].count,t1[i].unitprice,t1[i].totalprice);
	}
	fclose(fp);
	
	/*��ʾ�˳�������Ϣ*/
	Return();
	getch();
	return 0;
}