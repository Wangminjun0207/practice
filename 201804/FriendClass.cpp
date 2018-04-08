#include <iostream>
#include <math.h>
using namespace std;
class LINE;
class POINT
{
	int x, y, z;
	friend class LINE;
public:
	POINT(){}
	POINT(const POINT &){cout<<"调用复制构造函数！"<<endl;  } 
	POINT(int a, int b, int c):x(a),y(b),z(c){cout<<"A"<<endl;}
	void print(){cout<<x<<","<<y<<","<<z<<endl;}
	~POINT(){cout<<"调用析构函数！"<<endl;}
};
/********************************************************

 POINT(const POINT &){cout<<"调用复制构造函数！"<<endl;  } 
 这条语句不知道什么地方出了问题
 添加之后会在 line2.print();输出一个 nan 字符串 
 如果程序合适，输出的应该是一个double 类型的 length
 length应该等于5.19615
 
 ********************************************************/ 
class LINE{
	POINT a, b;
	double length;
public:
	LINE(int a1, int b1, int c1, int a2, int b2, int c2):a(a1,b1,c1),b(a2,b2,c2)
	{
		length = sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2)+(c1-c2)*(c1-c2));
		cout<<"B"<<endl;
	}
	LINE(const LINE &){cout<<"调用复制构造函数！"<<endl;}
	/*
	*这里的构建函数传引用就好了，不要用 LINE(POINT a,POINT b)，换成LINE(POINT& a,POINT& b)
	*/
	
	LINE(POINT& a,POINT& b)
	{
		length = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
		cout<<"C"<<endl;
	}
	void print(){cout<<length<<endl;}
	~LINE(){cout<<"调用析构函数！"<<endl;}
};
int  main()
{
	LINE line1(1,2,3,4,5,6);
	line1.print();
	POINT pt1(1,2,3),pt2(4,5,6);
	LINE line2(pt1,pt2);
	line2.print();
	return 0;

}

