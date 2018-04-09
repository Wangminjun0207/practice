#ifndef STUDENTMGR_H
#define STUDENTMGR_H
#include "Predefine.h"
#include "Student.h"
class StudentMgr
{
	public:
		StudentMgr();
		~StudentMgr();
		int InitStuArray(); 
		int PrintArr();
	protected:
		Student m_arrStuList[MAXSTUDENTNUMBER];
};

#endif
