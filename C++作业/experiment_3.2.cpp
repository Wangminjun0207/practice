/*
 *1、	再编写一个三角形类，输出三角形的面积（如果不能构成三角形则输出0）。
 *2、	再编写一个四边形类。尝试输出其面积或体积。
 *3、	给出相应的主函数以验证类的正确性。
 */



#include <iostream>
#include <math.h>
using namespace std; 
class TRIANGLE
{
	private:
		float  a, b, c;   //三角形的三条边
		float  area;      //三角形的面积 
	public:
		TRIANGLE(float x, float y, float z)
		{
			a = x;
			b = y;
			c = z;
		}
		float AREA(TRIANGLE p)
		{
			float f;
			if(p.a>0 && p.b>0 && p.c>0 && 
			  (p.a+p.b>p.c) && (p.a+p.c>p.b) && (p.b+p.c>p.a))
			  {
			  	//利用海伦公式计算三角形面积 
			  	f = (p.a+p.b+p.c)/2;
				p.area = sqrt(f*(f-p.a)*(f-p.b)*(f-p.c));
				return p.area; 
			  }
			else
				return 0;
		} 
} ;

class QUADRILATERAL
{
	private:
		float  a, b, c, d;   //四边形的四条边
		float  area;      //四边形的面积 
	public:
		QUADRILATERAL(float x, float y, float z, float w)
		{
			a = x;
			b = y;
			c = z;
			d = w;
		}
		float AREA(QUADRILATERAL p)
		{
			float f;
			if(p.a>0 && p.b>0 && p.c>0 && p.d>0 && (p.a+p.b+p.c>p.d) &&
			  (p.a+p.b+p.d>p.c) && (p.a+p.c+p.d>p.b) && (p.b+p.c+p.d>p.a))
			  {
			  	f = (p.a+p.b+p.c+p.d)/2;
				p.area = sqrt((f-p.a)*(f-p.b)*(f-p.c)*(f-p.d));
				return p.area; 
			  }
			else
				return 0;
		} 
};
int main()
{
	float a, b, c, d;
	cout<<"请输入四条边长：";
	cin>>a>>b>>c>>d;
	QUADRILATERAL Q(a,b,c,d); 
	cout<<"面积为 ："<<Q.AREA(Q)<<endl;
	cout<<"请输入三条边长：";
	cin>>a>>b>>c;
	TRIANGLE ZiMinTion(a,b,c);  // ZiMinTion意思是三角形
	cout<<"面积为 ："<<ZiMinTion.AREA(ZiMinTion)<<endl;
}

