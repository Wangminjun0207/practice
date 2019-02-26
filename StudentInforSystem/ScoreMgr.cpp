#include "ScoreMgr.h"

ScoreMgr::ScoreMgr()
{	
}

int ScoreMgr::InitArrScoList()
{
	ifstream inputfile("scorefile.txt");
	if(!inputfile)
	{
		cout<<"打开文件失败！"<<endl;
		exit(0);	
	}
	StudentMgr smgr;
	CourseMgr  cmgr;
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		Score score;
		Student student;
		student = smgr.GetStudent(i);
		score.SetStudent(student); 
	
		for(int j=0;j<MAXCOURSENUMBER;j++)
		{
			Course course;
			course = cmgr.GetCourse(j);
			score.SetCourse(course,j);
			float sco;
			inputfile>>sco;
			score.SetScore(sco,j);
		}
		m_arrScoList[i] = score;	
	}
	inputfile.close();
}

float ScoreMgr::SearchLowScore(int j)
{
	float score = 100;
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		if(m_arrScoList[i].GetScore(j) < score)
			score = m_arrScoList[i].GetScore(j);
	}
	return (float)score;
}

float ScoreMgr::SearchHighScore(int j)
{
	float score = 0;
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		if(m_arrScoList[i].GetScore(j) > score)
			score = m_arrScoList[i].GetScore(j);
	}
	return score;
}

float ScoreMgr::AverageScore(int j)
{
	float score = 0;
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		score = score +  m_arrScoList[i].GetScore(j); 
	}
	return score/MAXSTUDENTNUMBER;
}

int ScoreMgr::PassNumber(int j)
{
	int number = 0;
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		if(m_arrScoList[i].GetScore(j) >= 60)
			number++;
	}
	return number;
}

int ScoreMgr::NoPassNumber(int j)
{
	int number = 0;
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		if(m_arrScoList[i].GetScore(j) < 60)
			number++;
	}
	return number;
}

void ScoreMgr::SearchStuInfor(int i)
{
	cout<<m_arrScoList[i].GetStudent().GetNumber()<<"\t"<<m_arrScoList[i].GetStudent().GetStuName()<<"\t"
		<<m_arrScoList[i].GetStudent().GetStuGerden()<<"\t"<<m_arrScoList[i].GetStudent().GetStuGrade()<<endl;
}

void ScoreMgr::SearchStuScore(int j)
{
	system("cls");
	cout<<"学号	学生姓名	性别       学生班级	      课程编号   课程名称     老师姓名   老师电话      成绩"<<endl<<endl; 
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		cout<<m_arrScoList[i].GetStudent().GetNumber()<<"\t"<<m_arrScoList[i].GetStudent().GetStuName()<<"\t"
		    <<m_arrScoList[i].GetStudent().GetStuGerden()<<"\t"<<m_arrScoList[i].GetStudent().GetStuGrade()<<"\t";
	
			cout<<m_arrScoList[i].GetCourse(j).GetCourseNum()<<"\t"<<m_arrScoList[i].GetCourse(j).GetCourseName()<<"\t" 
			    <<m_arrScoList[i].GetCourse(j).GetTeachName()<<"\t"<<m_arrScoList[i].GetCourse(j).GetTeachTel()<<"\t"<<m_arrScoList[i].GetScore(j)<<endl;
			    
  		cout<<endl;
  	}
}

void ScoreMgr::SearchStuOneScore(int i)
{
	system("cls");
	cout<<endl<<endl<<"学号	学生姓名	性别       学生班级	    "<<endl; 
		cout<<m_arrScoList[i].GetStudent().GetNumber()<<"\t"<<m_arrScoList[i].GetStudent().GetStuName()<<"\t"
		    <<m_arrScoList[i].GetStudent().GetStuGerden()<<"\t"<<m_arrScoList[i].GetStudent().GetStuGrade()<<endl<<endl;
		cout<<"课程编号   课程名称     老师姓名   老师电话      成绩"<<endl;
		for(int j=0;j<MAXCOURSENUMBER;j++)
		{
			cout<<" "<<m_arrScoList[i].GetCourse(j).GetCourseNum()<<"  \t"<<m_arrScoList[i].GetCourse(j).GetCourseName()<<" \t" 
			    <<m_arrScoList[i].GetCourse(j).GetTeachName()<<" \t"<<m_arrScoList[i].GetCourse(j).GetTeachTel()<<" \t"<<m_arrScoList[i].GetScore(j)<<endl;
  		}	    
  		cout<<endl;
}


int ScoreMgr::PrintArr()
{
	for(int i=0;i<MAXSTUDENTNUMBER;i++)
	{
		cout<<m_arrScoList[i].GetStudent().GetNumber()<<"\t"<<m_arrScoList[i].GetStudent().GetStuName()<<"\t"
		    <<m_arrScoList[i].GetStudent().GetStuGerden()<<"\t"<<m_arrScoList[i].GetStudent().GetStuGrade()<<endl;
	
		for(int j=0;j<MAXCOURSENUMBER;j++)
		{
			cout<<m_arrScoList[i].GetCourse(j).GetCourseNum()<<"\t"<<m_arrScoList[i].GetCourse(j).GetCourseName()<<"\t" 
			    <<m_arrScoList[i].GetCourse(j).GetTeachName()<<"\t"<<m_arrScoList[i].GetCourse(j).GetTeachTel()<<"\t"<<m_arrScoList[i].GetScore(j)<<endl;
  		}
  		cout<<endl;
  	}
}


ScoreMgr::~ScoreMgr()
{	
}

