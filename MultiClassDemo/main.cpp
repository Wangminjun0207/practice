#include <iostream>
#include "BookMgr.h"
#include "User.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BookMgr bkmgr;
	//bkmgr.PrintBookList();
	User usr1(123456),usr2(2015464);
	bkmgr.BorrowBook(10001,usr1.GetUserID()); //借一本不存在的书 
	bkmgr.BorrowBook(1006,usr1.GetUserID());   //用户123456借书籍1006 
	bkmgr.BorrowBook(1006,usr2.GetUserID());	  //用户2015464重复借1006 
	
	//上面的代码就将用户和书籍联系起来了，通过借阅这个函数，把用户ID存到书籍的USERID里。 
	
	
	
	
	
	return 0;
}
