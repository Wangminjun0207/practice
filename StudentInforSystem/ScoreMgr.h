#ifndef SCOREMGR_H
#define SCOREMGR_H
#include "Predefine.h"
#include "Score.h"
#include "Student.h"
#include "StudentMgr.h"
#include "CourseMgr.h"
#include "Course.h"
class ScoreMgr
{
	public:
		ScoreMgr();
		~ScoreMgr();
		float PrintArr();
	protected:
		Score m_arrScoList[MAXSTUDENTNUMBER*MAXSCORENUMBER];
};

#endif

