#include <iostream>
#include <cmath>
using namespace std;

class SHAPE
{
public:
	virtual void Draw(){}
};

class COLORSHAPE : public SHAPE
{
	string m_color;
public:
	COLORSHAPE(string _color):m_color(_color){}
	string getColor(){return m_color;}
	void Draw()
	{
		cout<<"color:"<<m_color<<endl;
	}
	virtual void Calculate(){}
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

class POINT1:public COLORSHAPE
{
	int x,y;
public:
	POINT1(int a,int b,string color):COLORSHAPE(color){x=a;y=b;}
	void Draw(){cout<<"color:"<<getColor()<<","<<"x="<<x<<","<<"y="<<y<<endl;}
	int getx(){return x;}
	int gety(){return y;}
	void Calculate(){}
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

class LINE1 : public COLORSHAPE
{
	POINT1 a,b;
public:
	LINE1(int x1,int y1,string c1,int x2,int y2,string c2):a(x1,y1,c1),b(x2,y2,c2),COLORSHAPE(c1){}
	void Draw()
	{
		cout<<"color:"<<a.getColor()<<","<<"x="<<a.getx()<<","<<"y="<<a.gety()<<";"
		<<"color:"<<b.getColor()<<","<<"x="<<b.getx()<<","<<"y="<<b.gety()<<endl;
	}
	void Calculate()
	{
		float l = sqrt((a.getx()-b.getx())*(a.getx()-b.getx())+(a.gety()-b.gety())*(a.gety()-b.gety()));
		cout<<"length:"<<l<<endl;
	}
	float getLength()
	{
		float l = sqrt((a.getx()-b.getx())*(a.getx()-b.getx())+(a.gety()-b.gety())*(a.gety()-b.gety()));
		return l;
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

class RECTANGLE1:public COLORSHAPE
{
	LINE1 a,b;
public:
	RECTANGLE1(int x1,int y1,string c1,int x2,int y2,string c2,int x3,int y3,string c3,int x4,int y4,string c4):
	  a(x1,y1,c1,x2,y2,c2),b(x3,y3,c3,x4,y4,c4),COLORSHAPE(c1){}
	void Draw()
	{
		a.Draw();
		b.Draw();
	}
	void Calculate()
	{
		float s = a.getLength()*b.getLength();
		cout<<"area:"<<s<<endl;
	}
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

int main()
{
	POINT p1(1,2);
	LINE l1(1,2,3,4),l2(5,6,7,8);
	RECTANGLE r1(1,2,3,4,5,6,7,8),r2(10,20,30,40,50,60,70,80);
	CIRCLE c(2,1,2);
	TRIANGLE t(1,2,3,4,5,6);
	PRINT p(&p1,&l1,&l2,&r1,&r2,&c,&t);
	p.print();
	POINT1 pp(1,2,"red");
	pp.Draw();
	LINE1 l(1,2,"white",3,4,"black");
	l.Calculate();
	l.Draw();
	RECTANGLE1 r(1,2,"red",3,4,"bpown",5,6,"white",7,8,"green");
	r.Draw();
	r.Calculate();
}
