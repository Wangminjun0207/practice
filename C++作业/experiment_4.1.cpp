/*
 *问题4.1：以上程序有两大错误，试指出来，并改正之？
 *问题4.2：①中的类名约束是什么意思？能否取消类名约束？
 */
 
#include <iostream>
using namespace std;

class CBase
{
public:
	CBase(){}
	CBase(int a):a(a){}
//protected:
	void print()
	{
		cout<< "a=" << a << endl;
	}
private:
	int a;
};
class CDerive : public CBase
{
public:
	void print()
	{
		CBase::print();
		cout << "b=" << b << endl;
	}
private:
	int b;
};

int main()
{
	CDerive d;
	d.print();//protected 受保护成员不能再类外访问 
	CBase b;
	b.print();
}

