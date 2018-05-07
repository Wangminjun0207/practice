/*
 *1．定义点CPoint类作为基类，在此基础上派生出直线CLine类和圆CCircle类，并要求基类和各派生类具有以下特点：
 *a．CLine类含有计算直线长度和斜率的成员函数；
 *b．CCircle类含有计算圆面积的成员函数。
 */
 
#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
	private:
		float x1;
		float y1;
		float x2;
		float y2;
	public:
		CPoint(float _x1, float _y1, float _x2, float _y2)
		{
			x1 = _x1;
			y1 = _y1;
			x2 = _x2;
			y2 = _y2;
		}
		float get_x1() { return x1; }
		float get_y1() { return y1; }
		float get_x2() { return x2; }
		float get_y2() { return y2; }
};
class CLine : public CPoint
{
	public:
		CLine(float _x1, float _y1, float _x2=0, float _y2=0):CPoint(_x1, _y1, _x2, _y2) {}
		float length()
		{
			float x;
			float y;
			float l;
			x = get_x1() - get_x2();
			y = get_y1() - get_y2();
			l = sqrt(x*x+y*y);
			cout << "长度：" << l << endl;
		}
		float slope()
		{
			float x;
			float y;
			float k;
			x = get_x1() - get_x2();
			y = get_y1() - get_y2();
			k = x / y;
			cout << "斜率：" << k << endl;
		}
};
class CCircle : public CPoint
{
	public:
		CCircle(float _x1, float _y1, float _x2=0, float _y2=0):CPoint(_x1, _y1, _x2, _y2) {}
		float length()
		{
			float x;
			float y;
			float l;
			x = get_x1() - get_x2();
			y = get_y1() - get_y2();
			l = sqrt(x*x+y*y);
			return l;
		}
		float area()
		{
			float r;
			float s;
			r = length()/2;
			s = 3.14 * r * r;
			cout << "圆面积：" << s << endl;
		}
};
int main()
{
	CLine a(1,1,2,2);
	a.length();
	a.slope();
	CCircle b(1,1,2,2);
	b.area();
	return 0;
}


