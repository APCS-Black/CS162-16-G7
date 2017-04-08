
#pragma once
#include<ctime>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
struct Mytime {
    int hour,minute;
};

struct Date {
    int day,month,year;
};

struct g_Course
{
	char Coursecode[10]; // CTT008, CS161
	int Year;
	int Semester;
	char Coursename[80];
	char Lecturerusername[30];
	Date Startat; // date
	Date Endat; // date
	Mytime From;
	Mytime To;
	int  DateOfWeek; // Monday, Tuesday…
    char Class[10];
	int student_quantity;
	int *Singles;
	//16CLC1, 16CTT, 15CLC2,...
};
struct g_CourseNode
{
	g_Course data;
	g_CourseNode *next;
};
struct presence
{
	char Coursecode[10];
	int year;
	int semester;
	long studentid;
	int week[10];
};
struct presenceNode
{
	presence data;
	presenceNode *next;
};
class Check_inList {
private:
	presenceNode *head;
	presenceNode *tail;
	g_CourseNode *phead;
    g_CourseNode *ptail;

public:
    Check_inList(); // At the time the list is created, it will automatically load saved data from the list.
    void AddLast(presence inpresence);
	void checkIn(long student_id);
	void import_file();
	void export_file();
	int count_numberofWeek();
    int getCount();
    void Clear(); //Wipe the List off the memory, only call this at the END of the program.

};
