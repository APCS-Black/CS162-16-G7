#pragma once

#include "HeaderList.h"

struct Date {
    int day,month,year;
};

struct Score
{
	//char Coursecode[10]; // We won't need this since the score will be stored with the course.
	char StudentName[70];
	//int Year;
	//int Semester;
	int StudentID;
	double Midtermscore;
	double Labscore;
	double Finalscore;
};

struct ScoreNode{
    Score data;
    ScoreNode *next;
};

class ScoreBoard{
private:
    ScoreNode *head;
    int nCount;
    bool Available;
public:
    ScoreBoard();
    bool isAvailable();
    void MakeAvailable();
    void MakeUnavailable();
    void SetCount(int n);
    void AddFirst(Score inScore);
    void sb_Print(ofstream &fout);
    Score sb_Find(int StudentID);
    void sb_Rewrite(ofstream &fout);
    void Clear();//Wipe the List, Don't randomly call this please.
};

struct User
{
	char Username[20]; // StudentID
	char Fullname[30];
	char Email[30];
	int Mobilephone;
	int Type; // 0 – Student ; 1 – Academic staff; 2 – Lecturer
	char Password[20];
	char Class[10]; // 16CLC1, 16CLC2, 16CTT
};

struct g_Course //Global courses for the academic staff. Score will be stored here as well.
{
	char Coursecode[10]; // CTT008, CS161
	int Year;
	int Semester;
	char Coursename[80];
	char Lecturerusername[30];
	Date Startat; // date
	Date Endat; // date
	int From; // time
	int To; // time
	//char DateOfWeek; // Monday, Tuesday…
    char Class[10]; //16CLC1, 16CTT, 15CLC2,...
    int *Singles; //Storing students who retakes the class by Student ID
    ScoreBoard ScoreList;
};

struct Presence
{
	char Coursecode[10];
	int Year;
	int Semester;
	char StudentID[20];
	int Week;
};


