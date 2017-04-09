#ifndef G_COURSE_H_INCLUDED
#define G_COURSE_H_INCLUDED


struct Class;
class Check_inList;

#include "HeaderList.h"


//The Courses.txt will have this format:
/*
1st row: Total number of Courses
from the second row, each block is a course, a course will be structured like this.
Course code
Year
Semester
Course name
Lecturer username
Start At date
End at date
Start time
End time
Date of week
Class (00) if no class is specified
Number of retakers/Singe students Retakers/Single students. (Later class are elective and a whole class might not in 1 course)
Score list:
Total number of student if this number is 0 then the score is not yet inputed by the lecturer
Student ID
Student name
lab mid term Final
Repeat until the last student.

Ex:
CS162
2017
2
Introduction to computer science
dbtien
22/4/2017
22/5/2017
09 00
11 00 (24h format)
2
16CTT
2 1551034 1451022
70
1651001
Pham Hoang An
10 10 10
...

*/



/*---------------------------------------------------------------------*/


struct g_CourseNode{
    g_Course data;
    g_CourseNode *next;
};

class g_CourseList {
private:
    g_CourseNode *head;
    g_CourseNode *tail;
    int nCount;
public:
    g_CourseList(); // At the time the list is created, it will automatically load saved data from the list.
    void AddLast(g_Course inCourse); //Add a new course to the current list, order does not matter so add last because i like to.
    void ExportScore(int StudentID, int Year, int Semester, ofstream &fout, Class *in_class); //Print scoreboard of a single student within 1 semester to fout
    void ExportScore(char Coursecode[10], int Year, int Semester, ofstream &fout);//Print scoreboard of all student in a course to fout
    int getCount();//Return the amount of courses, for later convenience
    void Import(ifstream &fin, UserList uList, Check_inList checkinList, ClassList c_List);//Import new course from a file.
    g_Course *FindCourse(char Coursecode[10], int Year, int Semester);//Find a course, return a pointer to that course (for easy editing).
    //It will return NULL if Course is not found. By returning the pointer, you can edit this course(import score) directly
    void Clear(); //Wipe the List off the memory, only call this at the END of the program.

};



#endif // G_COURSE_H_INCLUDED
