#include "../Headers/HeaderList.h"

UserList::UserList()
{
	head = NULL;
	ifstream fin;
	fin.open("../Data/Users.txt");
	fin >> nCount;

	for (int i = 0; i < nCount; ++i)
	{
		User user;
		fin.get();
		fin.get(user.Username, 20, '\n');
		fin.get();
		fin.get(user.Fullname, 30, '\n');
		fin.get();
		fin.get(user.Email, 30, '\n');
		fin.get();
		fin >> user.Mobilephonel;
		fin >> user.Type;
		fin.get();
		fin.get(user.Password, 20, '\n');
		/*Input char** Class*/
		if (user.Type == 0)
		{
			*user.Class = new char*[2];
			user.Class = new char[10];
			fin.get();
			fin.get(user.Class[0], 10, '\n');
			fin.get();
		}
		else
		{
			if (user.Type == 2)
			{
				*user.Class = new char*[NumberOfLecturerCourses + 2];
				for (int j = 0; j < NumberOfLecturerCourses + 1; ++j)
					user.Class = new char[10];
			}
		}
		//-----------------------------------------------------------//
		AddHead(user);
	}
}

void UserList::AddHead(User user)
{
	UserNode *tmp = new UserNode;
	tmp->data = user;
	tmp->next = head;
	head = tmp;
}

int UserList::getCount()
{
	return nCount;
}

User *UserList::FindUser(char Username[])
{
	UserNode *curr = head;
	while (curr)
	{
		User *currUser = &curr->data;
		if (strcmp(currUser->Username, Username) == 0)
			return currUser;
		curr = curr->next;
	}
	return NULL;
}

void UserList::Clear()
{
	ofstream fout("../Data/Users.txt");
	fout << nCount << endl;
	while (head)
	{
		UserNode *tmp = head;
		fout << tmp->Username << endl;
		fout << tmp->Fullname << endl;
		fout << tmp->Email << endl;
		fout << tmp->Mobilephone << endl;
		fout << tmp->Type << endl;
		fout << tmp->Password << endl;
		if (tmp->Type == 0)
		{
			fout << tmp->Class[0] << endl;
			delete[] tmp->Class[0];
			delete[] tmp->Class[1];
			delete[] tmp->Class;
		}
		else
		{
			if (tmp->Type == 2)
			{
				for (int j = 0; j < NumberOfLecturerCourses + 1; ++j)
					delete[] tmp->Class[j];
				delete[] tmp->Class;
			}
		}
		head = head->next;
		delete tmp;
	}
}