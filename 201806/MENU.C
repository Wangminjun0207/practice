#include <stdio.h>
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

int get_key()
{
	keycode key;
	key.word = bioskey(0);
	return key.byte ? key.byte : key.word;
}

void DipItem(int row, int text_color, int back_color, char *menu_item)
{
	gotoxy(2,row);
	textbackground(back_color);
	textcolor(text_color);
	cputs(menu_item);
}

void output(int out, int x, int y, int width, int height)
{
	struct text_info *r;
	static int cury = 1;
	gettextinfo(r);
	window(40,10,60,18);
	textbackground(BLUE);
	if(cury == 1)
	clrscr();
	textcolor(LIGHTBLUE);
	gotoxy(1,cury++);
	cprintf("Item %d is selected!\n",out);
	window(x, y, x+width, y+height);
	gotoxy(r->curx, r->cury);
}

void Dialog(int x0,int y0,int iWidth,int iRow,char *sTitle,char *information[])
{
	int i, len;

	window(x0+1, y0+1, x0+iWidth+1, y0+iRow+1);
	textbackground(BLACK);
	clrscr();

	window(x0, y0, x0+iWidth, y0+iRow);
	textbackground(BLUE);
	clrscr();

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

	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,1);
		cprintf("%c",196);
		gotoxy(i,iRow+1);
		cprintf("%c",196);
	}

	for(i=2;i<=iRow;i++)
	{
		gotoxy(1,i);
		putch(179);
		gotoxy(iWidth,i);
		putch(179);
	}

	for(i=2;i<iWidth;i++)
	{
		gotoxy(i,3);
		putch(205);
	}

	gotoxy(1,3);
	putch(198);
	gotoxy(iWidth,3);
	putch(181);

	textcolor(BLACK);
	len = strlen(sTitle);
	gotoxy((iWidth-len)/2,2);
	cprintf("%s",sTitle);

	for(i=0;information[i];i++)
	{
		gotoxy(2,4+i);
		cprintf("%s",*(information+i));
	}
	gotoxy(2,8);
	textcolor(8);
	cputs(information[4]);

	gotoxy(iWidth+1,iRow+1);
}

void print(int i)
{
	if(i==4)
		DipItem(4,YELLOW,8,"1.computer        ");
	if(i==5)
		DipItem(5,YELLOW,8,"2.student         ");
	if(i==6)
		DipItem(6,YELLOW,8,"3.teacher         ");
	if(i==7)
		DipItem(7,YELLOW,8,"4.tools           ");
}


int main()
{
	char title[100] = "**** FILE ****";
	char *information[6] = {"1.computer","2.student","3.teacher","4.tools","5.job"};
	int key;
	int i=4;
	char *buf1;
	textbackground(LIGHTGRAY);
	clrscr();
	Dialog(10,10,20,8,title,information);
	buf1 = (char *)malloc(20*8*2);
	gettext(10,10,30,18,buf1);
	print(i);
	key = get_key();
	puttext(10,10,30,18,buf1);
	while(key != Esc)
	{
		switch(key)
		{
			case Up:if(i==4)
					{
						DipItem(4,YELLOW,8,"1.computer        ");
						break;
					}
					else
					i--;
					print(i);
					break;
			case Down:if(i==7)
					  {
						  DipItem(7,YELLOW,8,"4.tools           ");
						  break;
					  }
					  else
						i++;
					  print(i);
					  break;
			case Enter:print(i);
					   output(i-3,40,10,30,8);
					   break;
			default:break;
		}
		key = get_key();
		window(10,10,30,18);
		puttext(10,10,30,18,buf1);
	}
	return 0;
}