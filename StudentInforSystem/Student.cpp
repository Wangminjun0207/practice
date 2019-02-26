#include "Student.h"

Student::Student()
{
}

Student::Student(unsigned int nNumber, char *pName, int nGender, char *pGrade)
{
	m_nNumber = nNumber;
	strcpy(m_strName,pName);
	m_nGender = nGender;
	strcpy(m_strGrade,pGrade);
}

Student::~Student()
{
}


