#include "Score.h"
#include <fstream> 
#include <string.h>
Score::Score()
{		
}

Score::Score(Student &stu,Course &cour, float nScore)
{
	memcpy(&m_student,&stu,sizeof(Student));
	memcpy(&m_course,&cour,sizeof(Course));
	m_score = nScore;
}
 
Score::~Score()
{
}
