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
int main()
{
	float a, b, c;
	cout<<"请输入三条边长：";
	cin>>a>>b>>c;
	TRIANGLE ZiMinTion(a,b,c);  // ZiMinTion意思是三角形
	cout<<"面积为 ："<<ZiMinTion.AREA(ZiMinTion)<<endl;
}
