#ifndef BOOK_H
#define BOOK_H

class Book
{
	public:
		Book();
		Book(int nID,char *strName);
		~Book();
		//获取属性 
		int GetBookId(){return m_nBookId;}
		char *GetBookName(){return m_pstrBookName;}
		int GetBookStatus(){return m_nStatus;}
		int GetBookUserID(){return m_nUserid;}
		//赋值属性 
		int SetBookStatus(int nStatus){m_nStatus = nStatus;}
		int SetBookUserID(int nUserId){m_nUserid = nUserId;}
		
	protected:
		int m_nBookId;
		char m_pstrBookName[12];
		int m_nStatus;   //0，正常；1，借出;2，淘汰;3，待补充； 
		int m_nUserid;   //被谁借了保存在这里 
};

#endif
