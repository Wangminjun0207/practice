/*
 *在继承机制中，子类可以定义一个与父类具有相同原型的成员函数。如：父类具有 void 
 *f();  函数，子类也定义了一个 void f();  函数，此时称为覆盖。 请了解在覆盖机制下，如何
 *在子类中访问来自父类的 f 函数，如何在主函数中通过子类对象分别访问子类和父类的 f 
 *函数。 举例并运行实现，给出实现结论。
 */
 
#include <iostream>
#include <string>
using namespace std;
class STUDENT
{
	private:
		string m_Name;
		int m_Age;
		char m_Sex;
	public:
		STUDENT(string _name, int _age, char _sex)
		{
			m_Name = _name;
			m_Age = _age;
			m_Sex = _sex;
		}
		virtual void f()
		{
			cout<<"name:"<<m_Name<<endl; 
			cout<<"age:"<<m_Age<<endl; 
			cout<<"sex:"<<m_Sex<<endl; 
		}
		~STUDENT(){}
};
class CollegeSTUDENT : public STUDENT
{
	private:
		string m_Major;
		string m_Colloge;
	public:
		CollegeSTUDENT(string _name, int _age, char _sex, string _colloge, string _major)
					   :STUDENT(_name, _age, _sex)
		{
			m_Colloge = _colloge;
			m_Major = _major;
		}
		virtual void f()
		{
			STUDENT::f();
			cout<<"colloge:"<<m_Colloge<<endl; 
			cout<<"majir:"<<m_Major<<endl;
		}
		~CollegeSTUDENT(){}
};

int main()
{
	CollegeSTUDENT stu1("www",18,'M',"Infor","Computer");
	CollegeSTUDENT stu2("xxx",20,'F',"Infor","Computer");
	stu1.STUDENT::f();  //指明作用域调用基类的f()函数 
	STUDENT *stu = &stu1;
	stu->f(); //指向派生类的指针，调用派生类的虚函数 
	stu2.f();  //通过对象调用派生类f()函数 
	return 0;
}
