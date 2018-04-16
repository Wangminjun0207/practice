#include "Course.h"

Course::Course()
{
}

Course::Course(char *pSourNum, char *pSourName, char *pTeachName, char *pTeachTel)
{
	strcpy(m_strCourNum,pSourNum);
	strcpy(m_strCourName,pSourName);
	strcpy(m_strTeachName,pTeachName);
	strcpy(m_strTeachTel,pTeachTel);
}

Course::~Course()
{
}

