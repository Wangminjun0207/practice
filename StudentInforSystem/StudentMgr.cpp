#include "StudentMgr.h"
#include "Student.h"
#include <fstream>

StudentMgr::StudentMgr()
{
	unsigned int number;
	char name[12];
	int gerden;
	char grade[25];
	ifstream inputfile("studentfile.txt");
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		if(!inputfile)
		{
			cout<<"打开文件失败！"<<endl;
			exit(0);	
		}
		inputfile>>number>>name>>gerden>>grade;
		Student stu(number,name,gerden,grade);
		m_arrStuList[i]=stu;
	} 
	inputfile.close(); 	
}


int StudentMgr::PrintArr()
{
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{ 
		cout<<setw(5)<<m_arrStuList[i].GetNumber()<<setw(16)<<m_arrStuList[i].GetStuName()<<i<<setw(5)<<
			  m_arrStuList[i].GetStuGerden()<<setw(30)<<m_arrStuList[i].GetStuGrade()<<endl;
	}
}

StudentMgr::~StudentMgr()
{
}
