#ifndef COURSEMGR_H
#define COURSEMGR_H
#include "Predefine.h"
#include "Course.h"
class CourseMgr
{
	public:
		CourseMgr();
		~CourseMgr();
		int InitCourArray();
		int PrintArr();
	protected:
		Course m_arrCourList[MAXCOURSENUMBER];
};

#endif
