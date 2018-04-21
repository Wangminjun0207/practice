#include "Predefine.h"
#include "Student.h"
#include "StudentMgr.h"
#include "Course.h"
#include "CourseMgr.h"
#include "ScoreMgr.h"
#include "ComposeMgr.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	//student manager和Course Manager两个可以放到ComposeMgr里面初始化的 
	StudentMgr smgr;			//给所有同学初始化 
	CourseMgr  coumgr;			//给所有课程初始化		 
	ComposeMgr cmgr;           //定义一个综合管理类对象 
	cmgr.Manage();
	return 0;
}
