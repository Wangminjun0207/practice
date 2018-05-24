#include <graphics.h>
#include <stdio.h>
int main()
{
	int gdriver, gmode;
	int i,j,k;
	int point[10]={400,300,600,300,600,400,400,400,400,300};
	clrscr();
	detectgraph(&gdriver,&gmode);
	initgraph(&gdriver,&gmode,"E:\\TC20\DISK_C");
	setbkcolor(BLACK);
	setcolor(WHITE);
	cleardevice();
	line(450,50,550,50);
	line(450,50,400,100);
	line(400,100,500,100);
	line(550,50,500,100);
	line(400,100,400,200);
	line(400,200,500,200);
	line(500,100,500,200);
	line(550,50,550,150);
	line(500,200,550,150);
	setlinestyle(1,0xFF00,3);
	line(450,50,450,150);
	line(450,150,400,200);
	line(450,150,550,150);
	for(i=1,j=100,k=100;i<15;i++)
	{
		setcolor(i);
		circle(j,k,k/2);
		j=j+6;
		k=k+10;

	}
	setlinestyle(0,0xFFFF,1);
	drawpoly(5,point);
	getch();
	closegraph();
	cprintf("The graphics driver is %d, mode is %d",gdriver, gmode);
	getch();
	return 0;
}
