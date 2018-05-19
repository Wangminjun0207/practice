//外观模型的例子 

#include <iostream>
#include "facade.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Facade* f = new Facade();
	f->OperationWrapper();
	f->Test();
	return 0;
}
