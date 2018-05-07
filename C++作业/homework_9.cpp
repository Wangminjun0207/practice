/* 
 *写一个类，对成员函数的两种定义形态（类内定义和类外定义）进行验证
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
		STU(char a[],int b, float c)
		{
			strcpy(arrName,a);
			nNumber = b;
			score = c;
		}
		STU(const STU &);
		void print()
		{
			cout<<"arrName = "<<arrName<<endl;
			cout<<"nNumber = "<<nNumber<<endl;
			cout<<"score = "<<score<<endl;
		}
};
STU::STU(const STU &a)
{
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
