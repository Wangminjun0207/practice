#ifndef COURSEMGR_H
#define COURSEMGR_H
#include "Predefine.h"
#include "Course.h"
#include "StudentMgr.h"
class CourseMgr
{
	public:
		CourseMgr();
		~CourseMgr();
		int PrintArr();
	protected:
		Course m_arrCourList[MAXCOURSENUMBER];
};

#endif
