#ifndef SCORE_H
#define SCORE_H
#include "Predefine.h"
#include "Student.h"
#include "Course.h"
class Score
{
	public:
		Score();
        Score(Student &stu,Course &cour, float score);
		~Score();
		Student GetStudent(){return m_student;}
		Course GetCourse(int i){return m_course[i];}
		float GetScore(int i){return m_score[i];}
		void SetStudent(Student &stu){memcpy(&m_student,&stu,sizeof(Student));}
		void SetCourse(Course &course,int i){ memcpy(&m_course[i] ,&course,sizeof(Course));}
		void SetScore(float score, int i){m_score[i] = score;}
	protected:
		Student  m_student;
		Course  m_course[MAXCOURSENUMBER];
		float  m_score[MAXCOURSENUMBER];    
};
#endif
