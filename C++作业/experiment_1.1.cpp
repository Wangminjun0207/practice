/*
 *理解下面的程序，并在VC++6.0下运行查看结果，回答程序后面的问题
 */
 
 
#include <iostream>
using namespace std;
int max_def(int x, int y)
{
	return (x>y?x:y);
}
int max_def(int x, int y, int z)
{
	int temp = 0;
	return (temp=(x>y?x:y))>z?temp:z;
}
double max_def(double x, double y)
{
	return (x>y?x:y);
}
int main()
{
	int x1 = 0;
	int x2 = 0;
	double d1 = 0.0;
	double d2 = 0.0;
	x1 = max_def(5,6);
	x2 = max_def(2,3,4);
	d1 = max_def(2.1,5.6);
	d2 = max_def(12.3,3.4,7.8);//-----------------------------------------------------①
	cout<<"x1="<<x1<<endl;
	cout<<"x2="<<x2<<endl;
	cout<<"d1="<<d1<<endl;
	cout<<"d2="<<d2<<endl;//--------------------------------------------------------②
	return 1;
}


/*
 *问题1.1：上述程序的输出结果是什么？
 *问题1.2：哪些情况可以参与函数的重载？
 *问题1.3：①处调用的是哪个函数？
 */

