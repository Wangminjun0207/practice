#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <bios.h>
#define Esc    27
#define Enter  13
#define Up     0x4800
#define Down   0x5000
#define Left   0x4B
#define Right  0x4D

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

int main()
{
	int key;
	int i, gdriver, gmode, size;
	void *buf;
	gdriver = DETECT;
	initgraph(&gdriver,&gmode,"");
	setbkcolor(BLUE);
	cleardevice();
	setcolor(YELLOW);
	//ªÊ÷∆‘≤¡≥
	circle(100,200,30);
	floodfill(100,200,14);
	//ªÊ÷∆—€æ¶
	setcolor(BLACK);
	circle(85,185,5);
	floodfill(85,185,0);
	circle(115,185,5);
	floodfill(115,185,0);
	//ªÊ÷∆◊Ï∞Õ
	arc(100,200,225,315,20);
	size = imagesize(69,169,131,231);
	buf = malloc(size);
	getimage(69,169,131,231,buf);
	while(key != Esc)
	{
		switch(key)
		{
			case Up:
					break;
			case Down:
					  break;
			case Left:
					   break;
			case Right:
						break;
			default:break;
		}
		key = get_key();
		putimage(70,170,buf,COPY_PUT);
	}
	closegraph();
	return 0;
}