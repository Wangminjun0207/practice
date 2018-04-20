#include "CourseMgr.h"
#include <fstream> 
CourseMgr::CourseMgr()
{
	char m_number[12];
	char m_name[32];
	char m_teacherName[10];
	char m_teacherTel[15];
	ifstream inputfile("coursefile.txt");
	for(int i=0;i<MAXCOURSENUMBER;i++)
	{
		if(!inputfile)
		{
			cout<<"打开文件失败！"<<endl;
			exit(0);	
		}
		inputfile>>m_number>>m_name>>m_teacherName>>m_teacherTel;
		Course cour(m_number,m_name,m_teacherName,m_teacherTel);
		m_arrCourList[i]=cour;
	} 
	inputfile.close(); 
}


CourseMgr::PrintArr()
{
	cout<<"课程编号  课程名称      老师姓名   老师电话"<<endl;
	for(int i=0;i<MAXCOURSENUMBER;i++)
	{ 
		cout<<"  "<<m_arrCourList[i].GetCourseNum()<<"	  "<<m_arrCourList[i].GetCourseName()<<"	"<<
		      m_arrCourList[i].GetTeachName()<<"	  "<<m_arrCourList[i].GetTeachTel()<<endl;	
	}
	return 0;
}
CourseMgr::~CourseMgr()
{
}
