#include "ComposeMgr.h"
#include <fstream>
void Interface_1();
void Interface_2();
void Interface_3();
void Interface_4();
void AnalyzeOne();
void InterfaceEnd();
//ScoreMgr scoMgr;


ComposeMgr::ComposeMgr()
{
	
}

ComposeMgr::~ComposeMgr()
{
}
ComposeMgr::Manage()
{
	scoMgr.InitArrScoList();
	StudentMgr stumgr;
	int selectkey;
	do
	{
		int number;
		system("cls");
		Interface_1();
		cin>>selectkey;
		switch(selectkey)
		{
			case 1:system("cls");
				   cout<<"选择查询学生成绩功能！"<<endl<<endl;
				   cout<<"请输入学号：";
				   cin>>number; 
				   scoMgr.SearchStuOneScore(number-1);
				   system("pause");
				   break;
			case 2:system("cls");
				   cout<<"选择输出所有学生信息功能！"<<endl<<endl;
				   stumgr.PrintArr();
				   system("pause");
				   break;
			case 3:system("cls");
				   cout<<"选择分析单科成绩功能！"<<endl<<endl;
				   AnalyzeOne();
				   break;
			case 4:system("cls");
				   cout<<"选择查询学生信息功能！"<<endl<<endl;
				   cout<<"请输入学号：";
				   cin>>number; 
				   scoMgr.SearchStuInfor(number-1);
				   system("pause");
				   break;
			case 5:system("cls");
				   cout<<"选择输出所有成绩功能！"<<endl<<endl; 
				   scoMgr.PrintArr();
				   system("pause");
				   break;
			case 6:system("cls");
				   cout<<"选择输出单科成绩功能！"<<endl<<endl;
				   Interface_4(); 
				   cout<<"请选择课程：";
				   cin>>number;
				   scoMgr.SearchStuScore(number-1);
				   system("pause");
				   break;
			case 0:system("cls");
				   InterfaceEnd();
				   break;
		}
	}while(selectkey != 0);
}

//一级菜单，有以下七个功能 
void Interface_1()
{
	cout<<"\t1.查询学生成绩"<<endl;
	cout<<"\t2.输出学生信息"<<endl;
	cout<<"\t3.分析单科成绩"<<endl;
	cout<<"\t4.查询学生信息"<<endl;
	cout<<"\t5.输出所有成绩"<<endl;
	cout<<"\t6.输出单科成绩"<<endl;
	cout<<"\t0.退出管理系统"<<endl;
	cout<<"\t请选择需要的功能：";
}


//二级菜单，有以下六种功能 
void Interface_2()
{
	cout<<"\t1.输出最高分"<<endl;
	cout<<"\t2.输出最低分"<<endl;
	cout<<"\t3.输出平均分"<<endl;
	cout<<"\t4.输出及格人数"<<endl;
	cout<<"\t5.输出挂科人数"<<endl;
	cout<<"\t0.返回上级菜单"<<endl;
	cout<<"\t请选择需要的功能：";
 }


//二级菜单，有以下九种功能
/*
*这里为什么不从文件读取，要写死？这个是可以配置的。 
*/ 
void Interface_3()
{
	cout<<"\t1.线性代数"<<endl;
	cout<<"\t2.离散数学"<<endl;
	cout<<"\t3.高等数学"<<endl;
	cout<<"\t4.面向对象"<<endl;
	cout<<"\t5.大学英语"<<endl;
	cout<<"\t6.大学物理"<<endl;
	cout<<"\t7.大学体育"<<endl;
	cout<<"\t8.近现代史"<<endl;
	cout<<"\t0.返回上级菜单"<<endl;
	cout<<"\t请选择需要的功能：";
 }
 
 
 //二级菜单，有以下八种功能
 /*
*这里为什么不从文件读取，要写死？这个是可以配置的。 
*/ 
void Interface_4()
{
	cout<<"\t1.线性代数"<<endl;
	cout<<"\t2.离散数学"<<endl;
	cout<<"\t3.高等数学"<<endl;
	cout<<"\t4.面向对象"<<endl;
	cout<<"\t5.大学英语"<<endl;
	cout<<"\t6.大学物理"<<endl;
	cout<<"\t7.大学体育"<<endl;
	cout<<"\t8.近现代史"<<endl;
 }
void InterfaceEnd()
{
	cout<<endl<<endl<<endl<<"\t\t\t\t\t====================================="<<endl;
	cout<<"\t\t\t\t\t|                                   |"<<endl;
	cout<<"\t\t\t\t\t|        感谢您的使用，再见！       |"<<endl;
	cout<<"\t\t\t\t\t|  Thank you for your use,goodbye!  |"<<endl; 
	cout<<"\t\t\t\t\t|                                   |"<<endl;
	cout<<"\t\t\t\t\t====================================="<<endl<<endl<<endl<<endl; 
}

void AnalyzeOne()
{
	scoMgr.InitArrScoList();
	/*
	 *为什么要在每次使用成绩数组的时候再次初始化 
	 *scoMgr析构还是什么原因 
	 *是因为AnalyzeOne这个函数是全局的函数，不是定义在ComposeMgr类里面的，所以你在访问 scoMgr的时候，其实是访问的这个文件开头定义的scoMgr，并不是ComposeMgr类的那个成员。所以，如果你一定是需要访问ComposeMgr的类成员scoMgr，
	 *就需要把这个AnalyzeOne做为类成员函数，或者定义一个全局指针指向这个类成员的scoMgr，或者把scoMgr定义成一个静态成员，用一个静态方法全局调用。
	 *add by lottiwang@2018/04/21 
	 */ 
	int selectkey_1;
   	do
   	{
   		Interface_3();
   		cin>>selectkey_1;
   		if(selectkey_1 == 0)
   			break;
   		system("cls");
   		int selectkey_2;
   		do
   		{
   			Interface_2();
	   		cin>>selectkey_2; 
	   		switch(selectkey_2)
			{
				case 1:system("cls");
					   cout<<"选择输出最高分功能！"<<endl<<endl;
					   cout<<"最高分："<<scoMgr.SearchHighScore(selectkey_1-1)<<"分"<<endl<<endl;
					   system("pause");
					   break; 
				case 2:system("cls");
					   cout<<"选择输出最低分功能！"<<endl<<endl;
					   cout<<"最低分："<<scoMgr.SearchLowScore(selectkey_1-1)<<"分"<<endl<<endl;
				       system("pause");
				       break; 
				case 3:system("cls");
					   cout<<"选择输出平均分功能！"<<endl<<endl;
					   cout<<"平均分："<<scoMgr.AverageScore(selectkey_1-1)<<"分"<<endl<<endl; 
					   system("pause");
					   break; 
				case 4:system("cls");
					   cout<<"选择输出及格人数功能！"<<endl<<endl;
					   cout<<"及格人数："<<scoMgr.PassNumber(selectkey_1-1)<<"人"<<endl<<endl; 
					   system("pause");
					   break; 
				case 5:system("cls");
					   cout<<"选择输出挂科人数功能！"<<endl<<endl;
					   cout<<"挂科人数："<<scoMgr.NoPassNumber(selectkey_1-1)<<"人"<<endl<<endl;
					   system("pause");
					   break; 
				case 0:system("cls");
					   break; 
		   }
		}while(selectkey_2 != 0);
	}while(selectkey_1 != 0);	
} 
