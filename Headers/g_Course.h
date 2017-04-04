#ifndef G_COURSE_H_INCLUDED
#define G_COURSE_H_INCLUDED


#include "HeaderList.h"

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
    g_CourseList();
    void AddLast(g_Course inCourse);
    void ExportScore(int StudentID, int Year, int Semester);
    void ExportScore(char Coursecode[10], int Year, int Semester);
    int getCount();
    ~g_CourseList();

};



#endif // G_COURSE_H_INCLUDED
