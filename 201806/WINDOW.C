#include <stdio.h>
#include <string.h>
#include <conio.h>

void Dialog(int x0,int y0,int iWidth,int iRow,char *sTitle,char *information[])
{
	int i, len;
	char *buf;
	
	/*���汳��*/ 
	buf = (char *)malloc(80*25*2);
	gettext(1,1,80,25,buf);

	/*������Ӱ����*/ 
	window(x0+1, y0+1, x0+iWidth+1, y0+iRow+1);
	textbackground(BLACK);
	clrscr();

	/*�����Ի�����*/ 
	window(x0, y0, x0+iWidth, y0+iRow);
	textbackground(BLUE);
	clrscr();

	/*�Ľǻ���*/ 
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

	/*���߻���*/ 
	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,1);
		cprintf("%c",196);
		gotoxy(i,iRow+1);
		cprintf("%c",196);
	}

	/*���߻���*/ 
	for(i=2;i<=iRow;i++)
	{
		gotoxy(1,i);
		putch(179);
		gotoxy(iWidth,i);
		putch(179);
	}

	/*�ָ��߻���*/ 
	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,3);
		putch(205);
	}

	/*������*/ 
	gotoxy(1,3);
	putch(198);
	gotoxy(iWidth,3);
	putch(181);

	/*title�������*/ 
	textcolor(RED);
	len = strlen(sTitle);
	gotoxy((iWidth-len)/2,2);
	cprintf("%s",sTitle);

	/*information���*/ 
	textcolor(GREEN);
	for(i=0;*(information+i);i++)
	{
		gotoxy(2,4+i);
		cprintf("%s",*(information+i));
	}

	/*�����λ*/ 
	gotoxy(iWidth+1,iRow+1);
	getch();
	
	/*������ԭ*/ 
	puttext(1,1,80,25,buf);
	getch();
}


int main()
{   char title[100] = "******* NOTICE *******";
	char *information[3] = {"This is the first text window program",
							"press any key to begin you exploration ..."};
	int i;
	textbackground(WHITE);
	textcolor(BLACK);
	clrscr();
	for(i=1; i<600; i++)
	cprintf("%d",i);
	getch();
	Dialog(10,10,50,6,title,information);
}