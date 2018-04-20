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
		int InitArrScoList();			//初始化成绩对象数组 
		int PrintArr();					//输出所有成绩 
		float SearchLowScore(int j);    //找出单科最低分 
		float SearchHighScore(int j);	//找出单科最高分 
		float AverageScore(int j);	    //求出单科平均分 
		int PassNumber(int j);			//统计及格人数 
		int NoPassNumber(int j);		//统计不及格人数 
		void SearchStuInfor(int i); 	//查询一个人的信息 
		void SearchStuScore(int i);		//查询所有人的单科成绩 
		void SearchStuOneScore(int i);	//查询一个人的成绩 
	protected:
		Score m_arrScoList[MAXSTUDENTNUMBER];
};

#endif

