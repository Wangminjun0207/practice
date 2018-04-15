#ifndef BOOKMGR_H
#define BOOKMGR_H
#include "Book.h"
class BookMgr
{
	public:
		BookMgr();
		~BookMgr();
		int InitBookList();
		int PrintBookList();
		int BorrowBook(int nBookId,int nUserid);
	protected:
		Book bklist[100];		
};

#endif
