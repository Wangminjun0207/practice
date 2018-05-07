/*
 *编写一个类，对静态成员的应用过程和作用进行验证，并进行说明。
 *包括：私有静态数据成员，初始化，对象访问和类访问等
 */
 
#include <iostream>
using namespace std;
class A
{
	private:
		
		int m_nMonth;
		int m_nDay;
	public:
		static int m_nYear;
		A(){}
		A(int month, int day);
		~A(){}
		void getDate(){cout<<m_nYear<<"-"<<m_nMonth<<"-"<<m_nDay<<endl;}
		static int getYear(){return m_nYear;}
		int GetYear(){return A::m_nYear;}
};
int A::m_nYear = 2018;
A::A(int month, int day)
{
	m_nYear++;
	m_nMonth = month;
	m_nDay = day;
}
int main()
{
	A a(4,18);
	cout<<"类名访问：";
	cout<<A::getYear()<<endl;
	cout<<"对象访问：";
	cout<<a.GetYear()<<endl;
	cout<<"对象访问：";
	a.getDate();
}

