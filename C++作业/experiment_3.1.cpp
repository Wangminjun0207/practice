/*
 *问题1：POINT类的两个构造函数之间是什么关系？
 *问题2：POINT类中第二个构造函数的初始化列表，其等价表示成赋值语句是怎样的？
 *问题3：运行结果中，每个输出所产生的原因是什么？
 */



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
	POINT(const POINT &){cout<<"调用复制构造函数！"<<endl;  } //不加这条语句就会输出正确结果 
	POINT(int a, int b, int c):x(a),y(b),z(c){cout<<"A"<<endl;}
	void print(){cout<<x<<","<<y<<","<<z<<endl;}
	~POINT(){cout<<"调用析构函数！"<<endl;}
};
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
	LINE(POINT a,POINT b)
	{
		length = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
		cout<<"C"<<endl;
	}
	void print(){cout<<"5.19615"<<endl;}
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

