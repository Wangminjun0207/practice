#include <iostream>
using namespace std;

class CBase
{
protected:
	int a;
public:
	CBase(int a):a(a){	}
};

class CDerive1 : public virtual CBase
{
public:
	CDerive1(int a):CBase(a){ }
};

class CDerive2 : public virtual CBase
{
public:
	CDerive2(int a):CBase(a){ }
};

class CDerive : public CDerive1,public CDerive2
{
public:
	CDerive(int a):CBase(0),CDerive1(a),CDerive2(a){}
	int geta(){return a;}
};

int main()
{
	CDerive d(1);
	cout<<d.geta()<<endl;
}

