#ifndef SCORE_H
#define SCORE_H
#include "Predefine.h"
#include "Student.h"
#include "Course.h"
class Score
{
	public:
		Score();
        Score(Student &stu,Course &cour, float sco);
		~Score();
		Student GetStudent(){return m_student;}
		Course GetCourse(){return m_course;}
		float GetScore(){return m_score;}
	protected:
		Student  m_student;
		Course  m_course;  
		float  m_score;    
};
#endif
