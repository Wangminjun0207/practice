#include <iostream>
using namespace std;

class CComplex
{
public:
	CComplex(float x = 0.0, float y = 0.0)
	{
		real = x;
		imag = y;
	}
	CComplex operator + (CComplex &obj2)	
	{
		CComplex obj3(this->real + obj2.real, this->imag + obj2.imag);
		return obj3;
	}
	CComplex &operator++()
	{
		this->real += 1;
		this->imag += 1;
		return *this;
	}
	void print()	
	{
		cout<<real<<"+"<<imag<<"i"<<endl;
	}
	friend CComplex &operator--(CComplex &x);
private:
	float real;
	float imag;
};

CComplex &operator--(CComplex &x)
{
	x.real -= 1;
	x.imag -= 1;
	return x;
}
int main()
{
	CComplex obj1(2.1,3.2);
	CComplex obj2(3.6,2.5);
	cout<<"obj1=";
	obj1.print();
	cout<<"obj2=";
	obj2.print();
	CComplex obj3 = obj1 + obj2;
	cout<<"befor++, obj3=";
	obj3.print();
	++obj3;
	cout<<"after++, obj3=";
	obj3.print();
	--obj3;
	cout<<"after--, obj3=";
	obj3.print();
	CComplex obj4 = ++obj3;
	cout<<"obj4=";
	obj4.print();
	return 0;
}

