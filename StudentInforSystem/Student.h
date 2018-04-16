#ifndef STUDENT_H
#define STUDENT_H
#include "Predefine.h"
class Student
{
	friend class ScoreMgr;
	public:
		Student();
		Student(unsigned int nNumber, char *pName, int nGender, char *pGrade);
		unsigned int GetStuNum(){return  m_nNumber;}
		char *GetStuName(){return m_strName;}
		int GetStuGerden(){return m_nGender;}
		char *GetStuGrade(){return m_strGrade;}
		int GetNumber(){return m_nNumber;}
		~Student();
	protected:
		unsigned int m_nNumber;
		char m_strName[12];
		int m_nGender;
		char m_strGrade[30];
};

#endif
