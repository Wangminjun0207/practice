#include <iostream>
using namespace std;

class CBase1
{
public:
	CBase1(int a=0):a(a){	cout<<"base1 structure..."<<endl;	}
	~CBase1(){	cout<<"base1 destructure..."<<endl;	}
	void print(){	cout<<"a="<<a<<endl;	}
protected:
	int a;
};

class CBase2
{
public:
	CBase2(int b=0):b(b){	cout<<"base2 structure..."<<endl;	}
	~CBase2(){	cout<<"base2 destructure..."<<endl;	}
	void print(){	cout<<"b="<<b<<endl;	}
protected:
	int b;
};

class CDerive : public CBase1, public CBase2
{
public:
	CDerive(int a, int b, int c):CBase1(a),CBase2(b),c(c) {	cout<<"derive structure..." << endl;	}
	~CDerive(){	cout<<"derive destructure..."<<endl;	}
	void print()
	{
		CBase1::print();
		CBase2::print();
		b1.print();
		b2.print();
		cout<<"c="<<c<<endl;
	}
private:
	CBase1 b1;
	CBase2 b2;
	int c;
};
int main()
{
	CDerive d(1,2,3);
	d.print();
} 
