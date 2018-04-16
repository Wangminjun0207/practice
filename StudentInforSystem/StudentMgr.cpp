#include "StudentMgr.h"
#include "Student.h"
#include <fstream>

StudentMgr::StudentMgr()
{
	int nGer;
	ofstream outfile("studentfile.txt");
	if(!outfile)
	{
		cout<<"打开文件失败！"<<endl;
		exit(0);	
	}
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		if(i%2==0)
			nGer = 1;// 1 代表男生 
		else
			nGer = 0;// 0 代表女生 
		Student stu(001+i,"student",nGer,"计算机类2017-03班");
		m_arrStuList[i]=stu;
		outfile<<m_arrStuList[i].GetNumber()<<" "<<m_arrStuList[i].GetStuName()<<i<<" "<<
		m_arrStuList[i].GetStuGerden()<<" "<<m_arrStuList[i].GetStuGrade()<<endl;	
	} 
	outfile.close();		
}


int StudentMgr::PrintArr()
{
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		cout<<m_arrStuList[i].GetNumber()<<" "<<m_arrStuList[i].GetStuName()<<i<<" "<<
			  m_arrStuList[i].GetStuGerden()<<" "<<m_arrStuList[i].GetStuGrade()<<endl;
	}
}

StudentMgr::~StudentMgr()
{
}
