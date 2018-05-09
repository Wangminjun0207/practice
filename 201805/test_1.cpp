/*
 *构造函数和析构函数在对象创建和消亡时会自动调用
 *显示调用又会如何？
 */
 
 
  
#include <iostream>
using namespace std;
class A
{
	public:
		A()
		{
			cout<<"constructor"<<endl;
		}
		~A()
		{
			cout<<"destructor"<<endl;
		} 
};
int main()
{
	A a;
	a.A::A();   //显示调用构造函数,出现错误 ，P201出现
	a.~A();
}
