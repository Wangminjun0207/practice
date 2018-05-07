/*
 *  编辑并调试运行下面的程序，分析运行结果中的每一个输出产生的原因
 */

#include <iostream>
using namespace std;
class Complex
{
		double real, image;
	public:
		Complex(double r = 0.0, double i = 0.0)
		{
			real = r;
			image = i;
			cout<<"A"<<real<<endl;
		}
		Complex(Complex &c)
		{
			real = c.real;
			image = c.image;
			cout<<"B"<<real<<endl;
		}
		~Complex() {cout<<"C"<<real<<endl;}
		Complex add(Complex c)
		{
			real += c.real;
			image += c.image;
			cout<<"add"<<real<<endl;
			return *this;
		}
		Complex sub(Complex c)
		{
			real -= c.real;
			image -= c.image;
			cout<<"sunb"<<real<<endl;
			return *this;
		}
		double getreal(){return real;}
		double getimage(){return image;}
};

Complex mul(Complex c1, Complex c2)
{
	Complex c(c1.getreal()*c2.getreal()+c1.getimage()*c2.getimage(),
			  c1.getreal()*c2.getimage()+c1.getimage()*c2.getreal());
	cout<<"mul"<<c.getreal()<<endl;
	return c;
}

void print(Complex c)
{
	cout<<c.getreal()<<"+j"<<c.getimage()<<endl;
}

int main()
{
	Complex a ,b(1.2), c(2.3,5.5);
	Complex a1(c),a2=b;
	a = b.add(c).add(a2);
	a1.sub(a).sub(c);
	a2 = mul(a,a1);
	print(a1);
	print(a2);
	return 0; 
}
