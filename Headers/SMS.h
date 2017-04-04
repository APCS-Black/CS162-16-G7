#pragma once

#include "HeaderList.h"

struct Date {
    int day,month,year;
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
    DynamicArray Retakers; //Storing students who retakes the class by Student ID
};

struct Presence
{
	char Coursecode[10];
	int Year;
	int Semester;
	char StudentID[20];
	int Week;
};

struct Score
{
	char Coursecode[10]; // CTT008, CS161
	int Year;
	int Semester;
	char StudentID[20];
	double Midtermscore;
	double Labscore;
	double Finalscore;
};
