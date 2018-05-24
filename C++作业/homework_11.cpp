/*针对教案中的"外观模式"，理解其含义，并输入调试其源代码。
 *尝试对源代码进行扩展，体会其中的程序结构意义。 
 *1、给出源代码的运行结果。 
 *2、给出修改后能够成功运行的修改部分说明，及运行结果说明。 
 *3、对程序功能的扩展过程的心得？
 */


//Facade.h
#ifndef _FACADE_H_
#define _FACADE_H_
class Subsystem1
{
public:
 Subsystem1();
 ~Subsystem1();
 void Operation();
protected:
private:
};
class Subsystem2
{
public:
 Subsystem2();
 ~Subsystem2();
 void Operation();
protected:
private:
};
class Facade
{
public:
 Facade();
 ~Facade();
 void OperationWrapper();
protected:
private:
 Subsystem1* _subs1;
 Subsystem2* _subs2;
};
#endif //~_FACADE_H_

//Facade.cpp
#include <iostream>
using namespace std;
Subsystem1::Subsystem1()
{
}
Subsystem1::~Subsystem1()
{
}
void Subsystem1::Operation()
{
 cout<<"Subsystem1 operation.."<<endl;
}
Subsystem2::Subsystem2()
{
}
Subsystem2::~Subsystem2()
{
}
void Subsystem2::Operation()
{
 cout<<"Subsystem2 operation.."<<endl;
}
Facade::Facade()
{
this->_subs1 = new Subsystem1();
this->_subs2 = new Subsystem2();
}
Facade::~Facade()
{
 delete _subs1;
 delete _subs2;
}
void Facade::OperationWrapper()
{
 this->_subs1->Operation();
 this->_subs2->Operation();
}

//main.cpp
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
Facade* f = new Facade();
 f->OperationWrapper();
 return 0;
}
