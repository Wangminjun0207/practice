#include <stdio.h>
#include <graphics.h>
int main()
{
	int i, gdriver, gmode, size;
	void *buf;
	gdriver = DETECT;
	initgraph(&gdriver,&gmode,"");
	setbkcolor(BLUE);
	cleardevice();
	setcolor(YELLOW);
	//����Բ��
	circle(100,200,30);
	floodfill(100,200,14);
	//�����۾�
	setcolor(BLACK);
	circle(85,185,5);
	floodfill(85,185,0);
	circle(115,185,5);
	floodfill(115,185,0);
	//�������
	arc(100,200,225,315,20);
	size = imagesize(69,169,131,231);
	buf = malloc(size);
	getimage(69,169,131,231,buf);
	//�ƶ�Ц��ͼ��
	for(i=0;i<185;i++)
	{
		putimage(70+i,170,buf,COPY_PUT);
	}
	getch();
	closegraph();
}

