#include "ScoreMgr.h"

ScoreMgr::ScoreMgr()
{
	float m_score; 
	ifstream inputfile_1("studentfile.txt");
	if(!inputfile_1)
	{
		cout<<"打开文件失败！"<<endl;
		exit(0);	
	}
	ifstream inputfile_2("coursefile.txt");
	if(!inputfile_2)
	{
		cout<<"打开文件失败！"<<endl;
		exit(0);	
	}
	ifstream inputfile_3("scorefile.txt");
	if(!inputfile_3)
	{
		cout<<"打开文件失败！"<<endl;
		exit(0);	
	}
	for(int i=0;i<MAXSTUDENTNUMBER*MAXSCORENUMBER;i++)
	{
		unsigned int number;
		char name[12];
		int gerden;
		char grade[20];
		Score sco; 
		inputfile_1>>number>>name>>gerden>>grade;
		Student stu(number,name,gerden,grade);
		char cNumber[12];
		char cName[32];
		char tName[10];
		char tTel[15];
		inputfile_2>>cNumber>>cName>>tName>>tTel;
		Course cour(cNumber,cName,tName,tTel);
		inputfile_3>>m_score;
		Score score(stu,cour,m_score);
		m_arrScoList[i] = score; 
	} 
	inputfile_1.close(); 
	inputfile_2.close(); 
	inputfile_3.close();   
}

float ScoreMgr::PrintArr()
{
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		cout<<m_arrScoList[i].GetStudent().GetNumber()<<"\t"<<m_arrScoList[i].GetStudent().GetStuName()<<"\t"
		    <<m_arrScoList[i].GetStudent().GetStuGerden()<<"\t"<<m_arrScoList[i].GetStudent().GetStuGrade()<<endl;
	
		for(int j=0;j<MAXCOURSENUMBER;j++)
		{
			cout<<m_arrScoList[j].GetCourse().GetCourseNum()<<"\t"<<m_arrScoList[j].GetCourse().GetCourseName()<<"\t" 
			    <<m_arrScoList[j].GetCourse().GetTeachName()<<"\t"<<m_arrScoList[j].GetCourse().GetTeachTel()<<"\t"<<m_arrScoList[j].GetScore()<<endl;
  		}
  		cout<<endl;
   }
}

ScoreMgr::~ScoreMgr()
{	
}

