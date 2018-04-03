#include <iostream>
#include <string>
using namespace std;
class PERSON
{
	string name;
	string studentnumber;
	string gender;
	int age;
	public:
		PERSON(string n,string s,string g,int a)
		{
			name = n;
			studentnumber = s;
			gender = g;
			age = a;
		}
		string getname(){return name;}
		string getstudentnumber(){return studentnumber;}
		string getgender(){return gender;}
		int getage(){return age;}
};
int main()
{
	string myname,mysno,mygender;
	int myage;
	cout<<"请输入学号";cin>>mysno;
	cout<<"请输入姓名";cin>>myname; 
	cout<<"请输入性别";cin>>mygender;
	cout<<"请输入年龄";cin>>myage;
	PERSON me(myname,mysno,mygender,myage);
	cout<<me.getstudentnumber()<<endl<<me.getname()<<endl<<me.getgender()<<endl<<me.getage()<<endl; 
} 
	
