#include <iostream>
int Sum(int a, int b)
{
	std::cout << "int Sum(int a, int b)" << std::endl;
	return a + b; 
}
template<typename T>
T Sum(T a, T b)
{
	std::cout << "T Sum(T a, T b)" << std::endl;
	return a + b;
}
template<class T, int Val>
T Sum(T a)
{
	std::cout << "T Sum(T a)" << std::endl;
	return a + Val;
}
template<class T>
T Sum(T a = 1)
{
	std::cout << "T Sum(T a = 1)" << std::endl;
	return a;
}
template<class T1, class T2>
T1 Sum(T1 a, T2 b)
{
	std::cout << "T1 Sum(T1 a, T2 b)" << std::endl;
	T1 s;
	s = (T1)b + a;
	return s;
}
int main()
{
	int s = Sum(2,3);
	float s1 = Sum<float>(1.2,1.3);
	int s2 = Sum<int,5>(2); 
	float s3 = Sum<int>();
	double s4 = Sum<double,int>(5.55,4);
	std::cout << "2 + 3 = " << s << std::endl;
	std::cout << "1.2 + 1.3 = " << s1 << std::endl;
	std::cout << "2 + 5 = " << s2 << std::endl;
	std::cout << "ÎŞ²ÎÊı = " << s3 << std::endl;
	std::cout << "5.55  + 4 = " << s4 << std::endl;
	return 0;
 } 
