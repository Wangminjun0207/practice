#include <iostream>
#include "Student.h"
#include "StudentMgr.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
//	Student student(1001,"wmj",1,"¼ÆËã»úÀà2017-03°à");
//	std::cout<<student.GetNumber()<<std::endl;
	StudentMgr stuMgr;
	stuMgr.PrintArr();
	return 0;
}
