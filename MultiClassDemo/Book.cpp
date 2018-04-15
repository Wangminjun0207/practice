#include "Book.h"
#include "string.h"
Book::Book()
{
	m_nBookId = 1000001;
	strcpy(m_pstrBookName,"≤‚ ‘”√ È");
	m_nStatus = 0;
}

Book::Book(int nID,char *strName)
{
	m_nBookId = nID;
	strcpy(m_pstrBookName,strName);
	m_nStatus = 0;
}

Book::~Book()
{
}
