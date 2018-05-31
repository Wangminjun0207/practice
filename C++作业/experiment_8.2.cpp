/*
 *装饰模式的应用非常广泛，包括手机装饰物、病人手里的处方、针对某个问题的解决方案、
 *某个复杂几何图形的构成部分等。尝试对8.2.1例子进行修改，对一个图案（如：游戏中的
 *某个人物）进行构造，并输出其基本构成元素。--提示：图案类似手机，构成元素类似于
 *装饰物。
 */
 
#include <iostream>
#include <string>
 
using namespace std;
class Role
{  
public:  
	virtual void ShowDecorate() = 0;
};  
class Soldier : public Role
{
private:  
	string m_name;//人物名字 
	string m_gerden;//性别 
	string m_color;//衣服颜色 
	float  m_power;//代表攻击力
	float  m_lifeValue;//代表生命值 
public:  
	Soldier(string name,string gerden, string color, float power, float lifeValue)
	{
		m_name = name;
		m_gerden = gerden;
		m_color = color;
		m_power = power;
		m_lifeValue = lifeValue;
	}  
    void ShowDecorate() 
	{
		cout<<m_name<<"'s gerden: "<<m_gerden<<endl;
		cout<<m_name<<"'s clothes: "<<m_color<<endl;
		cout<<m_name<<"'s power: "<<m_power<<endl;
		cout<<m_name<<"'s liveValue:"<<m_lifeValue<<endl;
		cout<<m_name<<"deccorate: "<<endl;
	}  
};
class DecoratorRole : public Role
{
private:  
	Role *m_role;
public:  
	DecoratorRole(Role *role): m_role(role) {}
	virtual void ShowDecorate() { m_role->ShowDecorate(); }
};
class Decorator : public DecoratorRole
{
private:
	string Decorator_name;
public:
	Decorator(string dn,Role *role) : DecoratorRole(role) {Decorator_name=dn;} 
	void ShowDecorate()	
	{
		DecoratorRole::ShowDecorate();
		AddDecorate();
	}  
private:  
	void AddDecorate() { cout<<Decorator_name<<endl; }
}; 
int main()
{
	Role *role = new Soldier("别救我先舔包","男","热带雨林迷彩",20,100); 
	Role *rda = new Decorator("三级甲",role);
 	Role *rdb = new Decorator("三级头",rda);
	Role *rdc = new Decorator("三级包",rdb);
	Role *rdd = new Decorator("kar98k",rdc);
	Role *rde = new Decorator("M416",rdd);
	rde->ShowDecorate();
	delete rde;  
	delete rdd; 
	delete rdc; 
	delete rdb;
	delete rda;   
	delete role;  
	return 0;
}

