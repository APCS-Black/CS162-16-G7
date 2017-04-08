#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED

#include "HeaderList.h"

#define NumberOfLecturerCourses 99

struct UserNode
{
	User data;
	UserNode *next;
};

class UserList
{
private:
	UserNode *head;
	int nCount;
public:
	UserList();//At the time the list is created, it will automatically load saved data from the list.
	void AddHead(User user);//Add an new user to the current list, used mainly to read from file.
	int getCount();//Return the amount of users, for later convenience
	User *FindUser(char Username[]);//Find an user, return a pointer to that user (for easy editing).
    //It will return NULL if User is not found. By returning the pointer, you can edit this user directly
	void Clear();//Wipe the List off the memory, only call this at the END of the program.
};

#endif