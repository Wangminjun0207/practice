   #include <stdio.h>
   #include <graphics.h>
   #include <stdlib.h>
   void Draw(float a[],int n)
   {
	int i;
	char str[5];
	float max=0;
	int x;
	int M;
	for(i=0;i<n;i++)
	if(a[i]>max)
		max = a[i];
	M = max;
	if(M%100!=0 && M/100>0)
		M = (int)(max/100+1)*100;
	else if(M%100!=0 && M/100==0)
		M = (int)(max/10+1)*10;
	for(i=0;i<n;i++)
	a[i]=a[i]*440/M;
	x = 520/n;
	line(40,20,40,460);
	line(40,460,600,460);
	for(i=0;i<n;i++)
	{
		line(60+i*x,460,60+i*x,460-a[i]);
		line(60+i*x+10,460,60+i*x+10,460-a[i]);
		line(60+i*x,460-a[i],60+i*x+10,460-a[i]);
	}
	for(i=0;i<=10;i++)
	{
		line(40,460-44*i,600,460-44*i);
		moveto(10,460-44*i);
		itoa(i*(M/10),str,10);
		outtext(str);
	}
	for(i=0;i<n;i++)
	{
		moveto(60+i*x+3,465);
		itoa(i+1,str,10);
		outtext(str);
	}
   }

   int main()
   {
	int gdriver, gmode;
	int i;
	float a[100];
	int s;
	scanf("%d",&s);
	for(i= 0;i<s;i++)
	scanf("%f",&a[i]);
	detectgraph(&gdriver, &gmode);
	initgraph(&gdriver, &gmode,"C:\\TC\\BGI");
	setbkcolor(BLACK);
	setcolor(WHITE);
	Draw(a,s);
	getch();
	closegraph();
	return 0;
   }