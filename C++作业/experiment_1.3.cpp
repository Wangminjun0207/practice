/*
 *理解下面的程序，并在VC++6.0下运行查看结果，回答程序后面的问题。
 */
 
#include <iostream>
using namespace std;
void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int i = 5;
	int j = 10;
	cout<<"Before swap: i="<<i<<",j="<<j<<endl;
	swap(i,j);//-----------------------------------------------------①
	cout<<"After the first swap: i="<<i<<",j="<<j<<endl;
	swap(&i,&j);//-----------------------------------------------------②
	cout<<"After the second swap: i="<<i<<",j="<<j<<endl;
	return 1;
}

/*
 *问题3.1：上述程序的输出结果是什么？
 *问题3.2：①处函数调用后并不能实现两个数的交换，而②处却可以，为什么？
 *问题3.3：②处调用的是哪个重载函数？
 */

