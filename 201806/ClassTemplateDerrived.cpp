#include <iostream>
using namespace std;
template <class T1>

class Base
{
public:
	Base(T1 i):x(i){}
	void func(T1 a)
	{
		cout << "func(T a)" << endl;
		cout << "x = " << x << endl; 
	}
	T1 Getx()
	{
		return x;
	}
private:
	T1 x; 
};

template<class T1, class T2>
class Derived : public Base<int>//派生开始的时候就 
{
public:
	Derived(T1 i, T2 j):Base(i),y(j){}
	void func(T1 t1, T2 t2)
	{
		cout << "func(T1 t1, T2 t2)" << endl;
		cout << "x = " << Base::Getx() << "," << "y = " << y << endl;
	}
private:
	T2 y;
};

int main()
{
	Base<int>b1(5);
	b1.func(10);
	Derived<int, float>d(1.1,2.2);
	d.func(10,20);
	return 0;
}
