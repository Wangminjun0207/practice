#include "CourseMgr.h"

CourseMgr::CourseMgr()
{
	InitCourArray();
}
CourseMgr::InitCourArray()
{
	for(int i=0;i<MAXCOURSENUMBER;i++)
	{
		Course cour("1001","wmj","100","13830222203");
		//memcpy(&m_arrStuList[i],&stu,sizeof(Student));
	    m_arrCourList[i]=cour;	
	}
	return 0;
}

CourseMgr::PrintArr()
{
	for(int i=0;i<MAXCOURSENUMBER;i++)
	{
		std::cout<<m_arrCourList[i].GetTeachTel()<<std::endl;
	}
	return 0;
}
CourseMgr::~CourseMgr()
{
}
