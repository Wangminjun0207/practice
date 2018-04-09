#include "StudentMgr.h"

StudentMgr::StudentMgr()
{
	InitStuArray();
}

StudentMgr::InitStuArray()
{
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		Student stu(1001+i,"wmj",1,"¼ÆËã»úÀà2017-03°à");
		//memcpy(&m_arrStuList[i],&stu,sizeof(Student));
		m_arrStuList[i]=stu;	
	}
	return 0;
}

StudentMgr::PrintArr()
{
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		std::cout<<m_arrStuList[i].GetNumber()<<std::endl;
	}
}
StudentMgr::~StudentMgr()
{
}
