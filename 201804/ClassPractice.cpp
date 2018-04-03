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
	cout<<"a.x,a.y,b.x,b.y : ";
	cin>>d>>e>>f>>g;
	a.fun(d, e);
	b.fun(f, g);
	c.add(a, b, c);
	c.print();
}
