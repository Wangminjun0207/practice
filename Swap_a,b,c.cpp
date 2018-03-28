#include <iostream>
using namespace std;
void exchange(float &x, float &y, float &z)
{
	float temp;
	temp=z;
	z=y;
	y=x;
	x=temp;
}

int main()
{
	float a, b, c;
	cin>>a>>b>>c;
	cout<<"Before swap:"<<a<<b<<c<<endl;
	exchange(a,b,c);
	cout<<"After swap:"<<a<<b<<c<<endl;
	return 0;
}

