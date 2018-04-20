#include "Score.h"
#include <fstream> 
#include <string.h>
Score::Score()
{		
}

Score::Score(Student &stu,Course &cour, float score)
{
	/*
	memcpy(&m_student,&stu,sizeof(Student)); 
	memcpy(&m_course ,&cour,sizeof(Course));
	m_score = score;
	*/
}
 
Score::~Score()
{
}
