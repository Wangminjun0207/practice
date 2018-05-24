/*
 *问题一：解释PRINT类中构造函数的功能和print函数的执行过程，并分析运行结果。
 *问题二：严格来说，矩形由两个LINE构成的，不是四个POINT。请改写RECTANGLE类。
 *问题三：请增加CIRCLE类和TRIANGLE类，并重写PRINT类和主函数，给出运行结果。
 *问题四：正方形是一个特殊的矩形。请从RECTANGLE类派生并实现之。
 */ 


#include <iostream>
using namespace std;

class SHAPE
{
public:
	virtual void Draw(){}
};

class POINT:public SHAPE
{
	int x,y;
public:
	POINT(int a,int b){x=a;y=b;}
	void Draw(){cout<<x<<","<<y<<endl;}
	int getx(){return x;}
	int gety(){return y;}
};

class LINE:public SHAPE
{
	POINT a,b;
public:
	LINE(int x1,int y1,int x2,int y2):a(x1,y1),b(x2,y2){}
	void Draw()
	{
		cout<<a.getx()<<","<<a.gety()<<";"<<b.getx()<<","<<b.gety()<<endl;
	}
};

class RECTANGLE:public SHAPE
{
	LINE a,b;
public:
	RECTANGLE(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4):
	  a(x1,y1,x2,y2),b(x3,y3,x4,y4){}
	void Draw()
	{
		a.Draw();
		b.Draw();
	}
};

class SQUARE : public RECTANGLE
{
public:
	SQUARE(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4):
	  RECTANGLE(x1,y1,x2,y2,x3,y3,x4,y4){}
};

class CIRCLE : public SHAPE
{
	int radius;
	POINT a;
public:
	CIRCLE(int r, int x, int y):a(x,y){radius = r;}
	void Draw()
	{
		cout<<"r="<<radius<<","<<a.getx()<<","<<a.gety()<<endl;
	}
};

class TRIANGLE : public SHAPE
{
	POINT a,b,c;
public:
	TRIANGLE(int x1,int y1,int x2,int y2,int x3,int y3):a(x1,y1),b(x2,y2),c(x3,y3){}
	void Draw()
	{
		cout<<a.getx()<<","<<a.gety()<<";"<<b.getx()<<","<<b.gety()<<";"<<c.getx()<<","<<c.gety()<<endl;
	}
};

class PRINT
{
	SHAPE *p[7];
public:
	PRINT(SHAPE *s1,SHAPE *s2,SHAPE *s3,SHAPE *s4,SHAPE *s5,SHAPE *s6,SHAPE *s7)
	{
		p[0]=s1;p[1]=s2;p[2]=s3;p[3]=s4;p[4]=s5;p[5]=s6;p[6]=s7;
	}
	void print()
	{
		for(int i=0;i<7;++i) p[i]->Draw();
	}
};

void main()
{
	POINT p1(1,2);
	LINE l1(1,2,3,4),l2(5,6,7,8);
	RECTANGLE r1(1,2,3,4,5,6,7,8),r2(10,20,30,40,50,60,70,80);
	CIRCLE c(2,1,2);
	TRIANGLE t(1,2,3,4,5,6);
	PRINT p(&p1,&l1,&l2,&r1,&r2,&c,&t);
	p.print();
	SQUARE s(1,1,1,2,2,2,2,3);
	s.Draw();
}
