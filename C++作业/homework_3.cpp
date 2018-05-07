/*
 *编写两个类A和B，其中A中声明了友元B。验证B类函数成员可以访问A类的私有数据成员。
 */
 
#include <iostream>
using namespace std;
class A
{
	friend class B;
	private:
		int age;
	public:
		A(int n){age = n;}
		~A(){}
		int getAge(){return age;}
};
class B
{
	public:
		B(){}
		~B(){}
		int setAge(A &a){a.age += 1;}	
		int getAge(A &a){return a.age;}
};
int main()
{
	A a(5);
	cout<<"A类对象访问A类对象的私有成员 ："<<a.getAge()<<endl;
	B b;
	b.setAge(a);
	cout<<"B类对象访问A类对象的私有成员 ："<<b.getAge(a)<<endl;
}

