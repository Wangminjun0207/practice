#ifndef USER_H
#define USER_H

class User
{
	public:
		User();
		User(int nID);
		~User();
		
		int SetUserID(int nId){m_UserID = nId;}
		int GetUserID(){return m_UserID;}
	protected:
		int m_UserID;
};

#endif
