#include "Predefine.h"
#include "Student.h"
#include "StudentMgr.h"
#include "Course.h"
#include "CourseMgr.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	StudentMgr stuMgr;
	stuMgr.PrintArr();
	CourseMgr courMgr;
	courMgr.PrintArr();
	return 0;
}
