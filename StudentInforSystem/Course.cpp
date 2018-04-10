#include "Course.h"

Course::Course()
{
}

Course::Course(char *pSourNum, char *pSourName, char *pTeachName, char *pTeachTel)
{
	strcpy(m_strSourNum,pSourNum);
	strcpy(m_strSourName,pSourName);
	strcpy(m_strTeachName,pTeachName);
	strcpy(m_strTeachTel,pTeachTel);
}

Course::~Course()
{
}

