/*
 *设计一个汽车类Motor，该类具有可载人数、轮胎数、马力数、生产厂家和车主五个数据成员，
 *根据Motor类派生出Car类、Bus类和Truck类。其中Bus类除继承基类的数据成员外，还具有表示
 *车厢节数的数据成员Number；Truck类除继承基类的数据成员之外，还具有表示载重量的数据
 *成员Weight。每个类都具有成员函数Display，用于输出各类对象的相关信息。要求设计一个
 *统一的显示相关信息的全局函数ShowInfo在主函数种调用，主函数中不直接调用类里面的Display函数。
 */

#include <iostream>
#include <string>
using std::string;
class Motor
{
	int m_Capacity;//可载人数
	int m_TireNum;//轮胎数量
	int m_HorPower;//马力数
	string m_Factory;//生产厂家
	string m_CarHost;//车主 
public:
	Motor(int capacity,int tirenum, int hpower, string factory, string host)
	{
		m_Capacity = capacity;
		m_TireNum = tirenum;
		m_HorPower = hpower;
		m_Factory = factory;
		m_CarHost = host;
	}
	virtual void Display()
	{
		std::cout<<"可载人数:"<<m_Capacity<<std::endl;
		std::cout<<"轮胎数量:"<<m_TireNum<<std::endl;
		std::cout<<"马 力 数:"<<m_HorPower<<std::endl;
		std::cout<<"生产厂家:"<<m_Factory <<std::endl;
		std::cout<<"车    主:"<<m_CarHost<<std::endl;
	}
	~Motor(){}
}; 

class Bus : public Motor
{
	int m_Number;//车厢数
public:
	Bus(int capacity,int tirenum, int hpower, string factory, string host, int number):
	    Motor(capacity, tirenum, hpower, factory, host)	
	{
	   	m_Number = number;
	}
	void Display()
	{
		Motor::Display();
		std::cout<<"车 厢 数:"<<m_Number<<std::endl;
	}
	~Bus(){}
}; 

class Truck : public Motor
{
	int m_Weight;//载重量 
public:
	Truck(int capacity,int tirenum, int hpower, string factory, string host, int weight):
	    Motor(capacity, tirenum, hpower, factory, host)	
	{
	   	m_Weight = weight;
	}
	void Display()
	{
		Motor::Display();
		std::cout<<"载 重 量:"<<m_Weight<<std::endl;
	}
	~Truck(){}
}; 

void ShowInfo(Motor *ptr)
{
	ptr->Display();
}

int main()
{
	Motor m(5,4,18,"xxxxxxxx","www");
	Bus b(20,12,20,"xxxxxxxx","ttt",2);
	Truck t(4,32,48,"xxxxxxxx","yyy",100);
	std::cout<<"------Motor------"<<std::endl;
	ShowInfo(&m);
	std::cout<<"-------Bus-------"<<std::endl;
	ShowInfo(&b);
	std::cout<<"------Truck------"<<std::endl;
	ShowInfo(&t);
	return 0;
}












