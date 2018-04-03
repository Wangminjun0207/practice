#include <iostream>
using namespace std;
#include <math.h>
int distance(int a, int b, int c, int d)
{
	int dis = 0;
	dis=sqrt((a-c)*(a-c)+(b-d)*(b-d));
	return dis;
}
double distance(double a,double b,double c,double d)
{
	double dis = 0;
	dis=sqrt((a-c)*(a-c)+(b-d)*(b-d));
	return dis;
}

int main()
{
	int i,j,k,l;
	i=j=k=l=0;
	double m,n,o,p;
	m=n=o=p=0;
	cin>>i>>j>>k>>l;
	cout<<"整型数平面间两点间距离="<<distance(i,j,k,l)<<endl;
	cin>>m>>n>>o>>p;
	cout<<"双精度平面间两点间距离="<<distance(m,n,o,p)<<endl;
	return 0;
}

 

