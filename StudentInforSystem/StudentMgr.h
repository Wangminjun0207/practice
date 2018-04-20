#ifndef STUDENTMGR_H
#define STUDENTMGR_H
#include "Predefine.h"
#include "Student.h"
class StudentMgr
{
	public:
		StudentMgr();
		int PrintArr();
		Student GetStudent(int i) {return m_arrStuList[i];}
		~StudentMgr();
	protected:
		Student m_arrStuList[MAXSTUDENTNUMBER];
};

#endif
