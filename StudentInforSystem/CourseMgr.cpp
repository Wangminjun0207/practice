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
			/*
			*判断文件打开失败的时候，需要说清楚是什么文件失败了，需要做啥检查，你所有的文件错误信息都输出是这个，三个文件提示信息一样的。另外如果做的好，可以判断下如果这个文件不在，自己创建一个，就不报错了。 
			* 另外读文件的逻辑，这条如何无论都会走到的，比如你现在要管理的课程是 MAXCOURSENUMBER个，但是文件里是小于MAXCOURSENUMBER的，假如只有一个，你这条信息是一定会输出的，所以这部分代码这么写是有问题的，
			*你需要在读完了文件里所有的课程信息以后，break出循环。读文件是否结束，一般是用inputfile.eof()判断的，你这里判断也是不对的。同样的，StudentMgr类也是一样的。 
			*/
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
