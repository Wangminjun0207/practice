#include <iostream>
#include <fstream>
using namespace std;
 
class CEmergency
{
public:
	string m_name;
	CEmergency(string name):m_name(name){}
	virtual void EmerResPlan()=0;
	virtual void Location()=0;	
};

class CEarthquake : public CEmergency
{
public:
	CEarthquake(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"地震应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\earthquake.docx"<<endl<<endl;
	}
};

class CTyphoon : public CEmergency
{
public:
	CTyphoon(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"台风应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\typhoon.docx"<<endl<<endl;
	}
};

class CFlood : public CEmergency
{
public:
	CFlood(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"洪水应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\flood.docx"<<endl<<endl;
	}
};

class CDebFlow : public CEmergency
{
public:
	CDebFlow(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"泥石流应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\debrisFlow.docx"<<endl<<endl;
	}
};

class CDustStorm : public CEmergency
{
public:
	CDustStorm(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"沙尘暴应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\dustStorm.docx"<<endl<<endl;
	}
};

class CRob : public CEmergency
{
public:
	CRob(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"抢劫应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\rob.docx"<<endl<<endl;
	}
};

class CShot : public CEmergency
{
public:
	CShot(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"强杀应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\shot.docx"<<endl<<endl;
	}
};

class CCarAccident : public CEmergency
{
public:
	CCarAccident(string name):CEmergency(name){}
	void EmerResPlan()
	{
		cout<<"车祸应急预案，为确保人员安全，制定计划如下："<<endl;
	}
	void Location()
	{
		cout<<"存放位置E:\\Emergency\\carAccident.docx"<<endl<<endl;
	}
};

void Use(CEmergency *p)
{
	p->EmerResPlan();
	p->Location();
}

int main()
{
	CEarthquake earthquake("地震");
	Use(&earthquake);
	CTyphoon typhoon("台风");
	Use(&typhoon);
	CFlood flood("洪水");
	Use(&flood);
	CDebFlow debFlow("泥石流");
	Use(&debFlow);  
	CDustStorm dustStorm("沙尘暴");
	Use(&dustStorm);
	CRob rob("抢劫");
	Use(&rob);
	CShot shot("枪杀");
	Use(&shot);
	CCarAccident cAccident("车祸");
	Use(&cAccident);
	return 0;
}

