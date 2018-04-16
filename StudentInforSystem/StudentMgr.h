#ifndef STUDENTMGR_H
#define STUDENTMGR_H
#include "Predefine.h"
#include "Student.h"
class StudentMgr
{
	public:
		StudentMgr();
		int PrintArr();
		~StudentMgr();
	
	protected:
	Student m_arrStuList[MAXSTUDENTNUMBER];
};

#endif
