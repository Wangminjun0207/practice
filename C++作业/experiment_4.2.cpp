/*
 *问题4.3：以下程序的输出结果是什么，说明为什么？
 *问题4.4：②处语句执行完后，d.b.a的值为多少？
 */
 
 
#include <iostream>
using namespace std;

class CBase
{
public:
	CBase(int a):a(a)
	{
		cout << "base structure" << endl;
	}
	~CBase()
	{
		cout << "base destructure" << endl;
	}
	void print()
	{
		cout << "a="<< a << endl;
	}
	int get_a(){ return a;}
protected:
	int a;
};

class CDerive : public CBase
{
public:
	CDerive(int a, int b, int c):CBase(a),b(b),c(c)
	{
		cout << "derive structure" << endl;
	}
	~CDerive()
	{
		cout << "derive destructure" << endl;
	} 
	void print()
	{
		CBase::print();
		cout << "b.a=" << b.get_a() << endl;
		/*
		 *原来是cout << "b.a=" << b.a<< endl;
		 *修改后cout << "b.a=" << b.get_a() << endl;
		 *此处是通过对象d的对象成员来访问基类的受保护成员，属于类外访问 
		 * 因此在基类加入int get_a()函数实现实验目的
		 **/ 
		cout << "c=" << c << endl;
	}
private:
	int c;
	CBase b;
};

int main()
{
	CDerive d(1,2,3);   //2处 
	d.print();
} 
