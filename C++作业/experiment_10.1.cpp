/*
 *问题一：①处的运算符重载，为什么该函数的返回值要设计成CComplex类型？
 *问题二：③处的运算符重载函数调用就相当于"obj=operator+(obj1,obj2);"，但是为什么CComplex类中的运算符重载函数只设计了一个参数？
 *问题三：执行语句④后，分析obj1值的变化情况
 *问题四：将②函数的返回值修改为引用，再分析语句④执行后obj1的值变化。
 */ 


#include <iostream>
using namespace std;

class CComplex
{
public:
	CComplex(int x=0,int y=0){
		real = x;
		imag = y;
	}
	int real;
	int imag;
	CComplex operator + (CComplex obj1){//-------①
		CComplex obj2(real + obj1.real, imag + obj1.imag);
		return obj2;
	}
	CComplex operator - (CComplex obj1){//------ ②
		real-=obj1.real;
		imag-=obj1.imag;
		return *this;
	}
};

int main()
{
	CComplex obj1(100,30);
	CComplex obj2(20, 30);
	CComplex obj3(obj1), obj4(obj2);
	CComplex obj;
	obj = obj1+obj2; //-----------------------③
	obj=obj1-obj2-obj3-obj4; //---------------④
	cout << obj.real <<endl;
	cout << obj.imag << endl;
	return 0;
}

