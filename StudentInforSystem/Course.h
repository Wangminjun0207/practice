#ifndef COURSE_H
#define COURSE_H
#include "Predefine.h"
class Course
{
	public:
		Course();
		Course(char *pSourNum, char *pSourName, char *pTeachName, char *pTeachTel);
		char *GetTeachTel(){return m_strTeachTel;}
		~Course();
	protected:
		char m_strSourNum[12];
		char m_strSourName[32];
		char m_strTeachName[10];
		char m_strTeachTel[15]; 
};

#endif
