/*
 * 对几何学中的图形进行继承仿真。包括：从基础二维空间点，到二维带颜色的点，到三
 * 维空间点的派生关系，结合对象成员编程技术，构造线、圆（球）和矩形（立方体）等。
 * 对每一个几何图形都能够构造并输出其主要参数（点的坐标、线的长度、圆面积（球体积）、 
 * 矩形面积（立方体体积）。--自由组合，无需完全实现。
 */
 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//二维空间点类
class Two_DPoint
{
public:
	float x;
	float y;
	Two_DPoint(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	~Two_DPoint(){}
};

//二维空间带颜色电类
class ColorTwo_DPoint : public Two_DPoint
{
private:
	string color;
public:
	ColorTwo_DPoint(string _color,float _x, float _y):Two_DPoint(_x, _y) {color = _color;}
	void GetColor() { cout << "第一个点的颜色：" << color << endl;; }
	~ColorTwo_DPoint() {}
};

//三维空间点类
class Three_DPoint : public ColorTwo_DPoint
{
public:
	float z;
	Three_DPoint(string _color,float _x, float _y,float _z):ColorTwo_DPoint(_color, _x, _y){ z = _z; }
	void GetColor() { ColorTwo_DPoint::GetColor(); }
	~Three_DPoint() {}
};

//三维空间直线类
class Line :public Three_DPoint
{
private:
	float x1;
	float y1;
	float z1;
	string color1;
public:
	Line(string _color,string _color1,float _x, float _y,float _z,float _x1, float _y1,float _z1):Three_DPoint(_color, _x, _y, _z)
	{
		color1 = _color1;
		x1 = _x1;
		y1 = _y1;
		z1 = _z1;
	}
	void GetColor() 
	{ 
		Three_DPoint::GetColor(); 
		cout << "第二个点的颜色：" << color1 << endl;
	}
	void Length()
	{
		float l;
		l = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
		cout << "两点间直线的长度：" << l << endl;
	}
	~Line() {}
};

//三维空间球体积类
class Globe : public Three_DPoint
{
private:
	float radius;
public:
	Globe(float _radius, string _color,float _x, float _y,float _z):Three_DPoint(_color, _x, _y, _z)
	{ radius = _radius; }
	void Volume()
	{
		float V;
		V = 4*3.14*radius*radius*radius/3;
		cout << "以第一个点为圆心的圆的体积:" << V <<endl;
	}
	void GetColor() {Three_DPoint::GetColor();}
	~Globe() {}
};

int main()
{
	string color1;
	string color2;
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
	float radius;
	cout << "输入第一个点的颜色:";
	cin >> color1;
	cout << "输入第一个点的X坐标:";
	cin >> x1;
	cout << "输入第一个点的Y坐标:";
	cin >> y1;
	cout << "输入第一个点的Z坐标:";
	cin >> z1;
	cout << "输入第二个点的颜色:";
	cin >> color2;
	cout << "输入第二个点的X坐标:";
	cin >> x2;
	cout << "输入第二个点的Y坐标:";
	cin >> y2;
	cout << "输入第二个点的Z坐标:";
	cin >> z2;
	cout << "输入以第一个点为圆心的圆半径:";
	cin >> radius;
	Line line1(color1, color2, x1, y1, z1, x2, y2, z2);
	line1.Length();
	line1.GetColor();
	Globe globe1(radius, color1, x1, y1, z1);
	globe1.Volume();
	return 0;
}

