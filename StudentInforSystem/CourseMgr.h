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
		Course GetCourse(int i){return m_arrCourList[i];}
	protected:
		Course m_arrCourList[MAXCOURSENUMBER];
};

#endif
