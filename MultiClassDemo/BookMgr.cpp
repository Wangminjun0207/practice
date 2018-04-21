#include "BookMgr.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include <iostream>
char * IntToStr(int Number);

BookMgr::BookMgr()
{
	InitBookList();
}

BookMgr::~BookMgr()
{
}

BookMgr::InitBookList()
{
	for(int i=0; i < 100; i++)
	{
		Book bk(1000+i,IntToStr(i+500));
		memcpy(&bklist[i],&bk,sizeof(Book));
	}	
}

BookMgr::PrintBookList()
{
	for(int i=0; i < 100; i++)
	{
		std::cout << "书籍ID：" << bklist[i].GetBookId() << " 书籍名称: " <<  bklist[i].GetBookName() << " 书籍状态: " << bklist[i].GetBookStatus()  << std::endl;
	}
}

int BookMgr::BorrowBook(int nBookId,int nUserid)
{
	int i=0;
	for(; i < 100; i++)
	{
		if( bklist[i].GetBookId() == nBookId)
		{
			if (bklist[i].GetBookStatus() <= 0)
			{
				bklist[i].SetBookStatus(1);
				bklist[i].SetBookUserID(nUserid);
				std::cout << "书籍ID：" << bklist[i].GetBookId() << " 书籍名称: " <<  bklist[i].GetBookName() <<
				           "被用户 " << nUserid << "借出，当前状态: " << bklist[i].GetBookStatus()  << std::endl;
				
			}
			else
			{
				std::cout << "书籍ID：" << bklist[i].GetBookId() << " 书籍名称: " <<  bklist[i].GetBookName() <<
				          "不能被用户" << nUserid << "借出，当前借用户: " << bklist[i].GetBookUserID()  << std::endl;
			}
			break;
			
		}	
		
	}
	if (i >= 100)
	{
		std::cout << "未找到ID：" << nBookId << " 的书籍"<< std::endl;
	}
	
	return 0;
}


char * IntToStr(int Number)
{

	char ch,*str,*t;
	int i,Temp,Len=0;
	str = (char *)malloc(11*sizeof(char));
	t = str;
	Temp =Number;
	while(Temp != 0)
	{
		*t = (Temp%10)+0x30;
		Temp = Temp/10;
		Len++;
		t++;
	}
	*t = '/0';
	t = str;
	for(i=0;i<Len/2;i++)
	{
		ch = *t;
		*t = *(t+Len-2*i-1);
		*(t+Len-2*i-1) = ch;
		t++;
	}
	return str;
} 
