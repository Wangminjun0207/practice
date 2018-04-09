#ifndef STUDENT_H
#define STUDENT_H
#include "Predefine.h"
class Student
{
	public:
		Student();
		Student(unsigned int nNumber, char *pName, int nGender, char *pGrade);
		~Student();
		int GetNumber(){return m_nNumber;}
		int InitStuArray();
	protected:
		unsigned int m_nNumber;
		char m_strName[12];
		int m_nGender;
		char m_strGrade[30];
};

#endif
