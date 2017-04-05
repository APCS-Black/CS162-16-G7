#ifndef G_COURSE_H_INCLUDED
#define G_COURSE_H_INCLUDED


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
Class
Number of retakers Retakers.
Score list:
Total number of student
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
9:00:00
11:00:00
16CTT
2 1551034 1451022
70
1651001
Pham Hoang An
10 10 10
...

*/

struct ScoreNode{
    Score data;
    ScoreNode *next;
};

class ScoreBoard{
private:
    ScoreNode *head;
    int nCount;
public:
    ScoreBoard();
    void SetCount(int n);
    void AddFirst(Score inScore);
    void Clear();//Wipe the List, Don't randomly call this please.
};

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
    void AddLast(g_Course inCourse);
    void ExportScore(int StudentID, int Year, int Semester);
    void ExportScore(char Coursecode[10], int Year, int Semester);
    int getCount();
    void Clear(); //Wipe the List off the memory, only call this at the END of the program.

};



#endif // G_COURSE_H_INCLUDED
