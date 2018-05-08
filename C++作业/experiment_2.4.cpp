/*
 *编写一个类，能够实现对数组长度进行改变。包括数组的初始长度定义、数组长度增加、数组长度压缩。
 */
 
#include <iostream> 
using namespace std;
class A{
	public:
		void init(int n);
		void write(int m,int n);
		void write(int n);
		void extend(int n);
		void destroy() { delete [] p_2; } 
	private:
		int *p_1;
		int *p_2;
		int *p_3;	
};
void A::init(int n)
{
	int i; 
 	 p_1=new int[n];
 	 for(i=0;i<n;i++)
 	 {
 	 	p_1[i]=0;
 	 	cout<<p_1[i]<<" ";
	}
	cout<<endl; 
} 
void A::write(int m,int n)
{
	int i;
	for(i=0; i<20;i++)
	{
		if(p_1[i]==0)
			{
				p_1[i] = 10 + 2*i;
				cout<<p_1[i]<<" ";
			}
		else
			; 
	}
	cout<<endl;
}
void A::extend(int n)
{
	if(n>=0)
	{
	p_2= new int[20+n];
	int i;
	for(i=0; i<20+n; i++)
	{
		if(i<20)
			p_2[i]=p_1[i];
		else
			p_2[i]=0;
		cout<<p_2[i]<<" ";
	}
	cout<<endl;
	delete [] p_1;
	}
	else
	{
	p_3= new int[30+n];
	int i;
	for(i=0; i<30+n; i++)
	{
		p_3[i]=p_2[i];
		cout<<p_3[i]<<" ";
	}
	cout<<endl;
	delete [] p_2;
	}
}
void A::write(int n)
{
	int i;
	for(i=0; i<30; i++)
	{
		if(p_2[i]==0)
		p_2[i]=n;
		cout<<p_2[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	A a;
	a.init(20);
	a.write(10,2);
	a.extend(10);
	a.write(20);
	a.extend(-5); 
	a.destroy();
	return 0;
}

