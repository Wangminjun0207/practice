#ifndef COURSE_H
#define COURSE_H
#include "Predefine.h"
class Course
{
	public:
		Course();
		Course(char *pSourNum, char *pSourName, char *pTeachName, char *pTeachTel);
		char *GetCourseNum(){return m_strCourNum;}
		char *GetCourseName(){return m_strCourName;}
		char *GetTeachName(){return m_strTeachName;}
		char *GetTeachTel(){return m_strTeachTel;}
		~Course();
	protected:
		char m_strCourNum[12];
		char m_strCourName[32];
		char m_strTeachName[10];
		char m_strTeachTel[15]; 
};

#endif
