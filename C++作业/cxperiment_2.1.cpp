#include <iostream>
using namespace std;
class A
{
	public:
		int x, y;
};
int main()
{
	A a, b, c;
	cin>>a.x>>a.y>>b.x>>b.y;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	cout<<c.x <<c.y <<endl;
}

/*
 *问题1：以上程序运行后实现什么功能？
 *问题2：如果将x和y都改成私有成员，为了实现相同的功能，类A和main函数应如何修改？请编写修改后的类成员函数定义和对应的main函数，并成功运行。
 *问题3：在问题2.2结果的基础上，将加法运算设计为类的成员函数，并适当修改main达成相同的效果。
 *问题4：在问题2.3的基础上，将类的每个成员函数都增加必要的输出信息，重新运行程序，观察并分析输出结果。
 */


/*
 *问题2.2答案
  #include <iostream> 
using namespace std;
class A{
	private:
		int x,y;
	public:
		void fun(int n, int m);
		void print();
};

void A::fun(int n, int m)
{
	x = n;
	y = m;
}

void A::print()
{
	cout<<x<<y<<endl;
}

int main()
{
	A a;
	int c,d,e,f,h,i;
	cin>>c>>d>>e>>f;
	h = c+e;
	i = d+f;
	a.fun(h,i);
	a.print();
return 0;
}
*/

/*
 *问题2.3答案
  #include <iostream> 
using namespace std;
class A{
	private:
		int x,y;
	public:
		void fun(int n, int m) {x = n;  y = m;}
		void print() {cout<<x<<y<<endl;}
		void add(A &i, A &j, A &k)
		{
			k.x = i.x + j.x;
			k.y = i.y + j.y;
		}
};
int main()
{
	A a, b, c;
	int d,e,f,g;
	cin>>d>>e>>f>>g;
	a.fun(d, e);
	b.fun(f, g);
	c.add(a, b, c);
	c.print();
}
*/

/*
 *问题2.4答案
  #include <iostream> 
using namespace std;
class A{
	private:
		int x,y;
	public:
		void fun(int n, int m) {x = n;  y = m; cout<<"成功赋值!"<<endl;}
		void print() {cout<<"x="<<x<<",y="<<y<<endl;}
		void add(A &i, A &j, A &k)
		{
			k.x = i.x + j.x;
			k.y = i.y + j.y;
			cout<<"加法计算完成！"<<endl; 
		}
};
int main()
{
	A a, b, c;
	int d,e,f,g;
	cout<<"a.x, a.y, b.x, b.y : ";
	cin>>d>>e>>f>>g;
	a.fun(d, e);
	b.fun(f, g);
	c.add(a, b, c);
	c.print();
}
*/ 
