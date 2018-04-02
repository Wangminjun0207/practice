#include <iostream> 
using namespace std;
class A{
	public:
		void run(int n);
};
void A::run(int n)
{
	int *p = new int[n];
	int  i;
	p[0]=p[1]=1;
	cout<<p[0]<<"	"<<p[1]<<"	";
	for(i=2;i<n;i++)
	{
		p[i] = p[i-2] + p[i-1];
		cout<<p[i]<<"	";
	}
	cout<<endl;
}
int main()
{
	A a;
	a.run(20);
	return 0;
}
