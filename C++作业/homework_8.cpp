/*
 *针对类使用过程中的各类问题（包括私有成员的访问等）进行验证，并说明各种错误在编译时的报错描述。 
 */
 
#include <iostream>
#include <string.h>
using namespace std;
class STU
{
	private:
		char arrName[10];
		int  nNumber;
		float score;
	public:
		STU() {cout<<"调用构造函数！"<<endl;	}
		STU(char a[],int b, float c)
		{
			strcpy(arrName,a);
			cout<<"访问私有成员arrName"<<endl;
			nNumber = b;
			cout<<"访问私有成员nNumber"<<endl;
			score = c;
			cout<<"访问私有成员score"<<endl;
		}
		STU(const STU &);
		void print()
		{
			cout<<"arrName = "<<arrName<<endl;
			cout<<"nNumber = "<<nNumber<<endl;
			cout<<"score = "<<score<<endl;
		}
~STU(){cout<<"调用析构函数！"<<endl;}
};
STU::STU(const STU &a)
{
	cout<<"调用复制构造函数！"<<endl; 
	strcpy(this->arrName,a.arrName);
	this->nNumber =  a.nNumber;
	this->score = a.score;
}
int main()
{
	STU student_1("Li Si",201701,88.8);
	STU student_2(student_1);
	student_2.print();
	return 0;
}

