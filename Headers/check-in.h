
#pragma once

#include "HeaderList.h"
#include "g_Course.h"

struct presenceNode
{
	presence data;
	presenceNode *next;
};
class Check_inList {
private:
	presenceNode *head;
	presenceNode *tail;

public:
    Check_inList(g_CourseList CourseList); // At the time the list is created, it will automatically load saved data from the list.
    void AddLast(presence inpresence);
	void checkIn(long student_id, g_CourseList CourseList);
	//void import_file(g_CourseList CourseList);
	void export_file(g_CourseList CourseList);
	void AddaStudent(long StudentID, char CourseCode[], int Year, int Semester);
	int count_numberofWeek(g_Course *Course);
    int getCount();
    void Clear(); //Wipe the List off the memory, only call this at the END of the program.

};
