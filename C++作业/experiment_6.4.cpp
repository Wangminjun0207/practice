#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	string m_Name;
	string m_ID;
	Person(string name, string id):m_Name(name),m_ID(id){}
	void print()
	{
		cout << "name   :" << m_Name << endl;
		cout << "ID     :" << m_ID << endl;
	}
	~Person(){}
};

class Stud
{
public:
	string m_Addr;
	string m_Tel;
	Stud(string addr, string tel):m_Addr(addr),m_Tel(tel) {}
	void print()
	{
		cout<<"addr   :"<<m_Addr<<endl;
		cout<<"tle    :"<<m_Tel<<endl;
	}
}; 

class Teacher : public Person
{
public:
	string m_Degree;
	string m_Dep;
	Teacher(string name, string id, string degree, string dep):Person(name, id)
	{
		m_Degree = degree;
	    m_Dep = dep;
	}
	void print()
	{
		Person::print();
		cout<<"degree :"<<m_Degree<<endl;
		cout<<"dep    :"<<m_Dep<<endl;
	}
	~Teacher(){}
};

class Student : public Person
{
public:
	int m_nOld;
	string m_Number;
	Student(string name, string id, int old, string number):Person(name, id)
	{
		m_nOld = old;
		m_Number = number;
	}
	void print()
	{
		Person::print();
		cout<<"old    :"<<m_nOld<<endl;
		cout<<"number :"<<m_Number<<endl;
	}
	~Student(){}
};

class Score : public Student, public Stud
{
public:
	float m_Math;
	float m_English;
	Score(string name, string id, string addr, string tel, int old, string number, float math, float english):Student(name, id, old, number),Stud(addr, tel)
	{
		m_Math = math;
		m_English = english;
	}
	void print()
	{
		Student::print();
		Stud::print();
		cout<<"math   :"<<m_Math<<endl;
		cout<<"english:"<<m_English<<endl;
	}
};



int main()
{
	cout<<"The student:"<<endl;
	Score c1("www","622429********5711","southwest jiaotong university","138****2203",20,"2017****81",88,99);
	c1.print();
	cout<<endl<<"The teacher:"<<endl;
	Teacher t1("www","622429********5710","professor","1111111.00");
	t1.print();
}

