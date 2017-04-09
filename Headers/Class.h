#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

#include "HeaderList.h"
class Check_inList;


struct StudentNode {
    int StudentID;
    StudentNode *next;
};

class StudentList {
private:
    StudentNode *head;
public:
    StudentList(); // set head = NULL
    void AddStudent(int StudentID);
    void AddtoCheckin(Check_inList &checkinList, char CourseCode[], int Year, int Semester);//Go through every student and add them to Check_inList with AddaStudent;
    void ClearList ();
};

struct Class {
    char ClassName[10];
    int StudentCount;
    StudentList s_List;
};

struct ClassNode {
    Class data;
    ClassNode *next;
};

class ClassList {
private:
    ClassNode *head;
    int nCount;
public:
    ClassList(); //Load class list from data file.
    Class *FindClass(int StudentID); //Find the class of a student.
    Class *FindClass(char ClassName[]); //Return a pointer to the class, to access the whole list of student.
    void ClearList();//Remeber to rewrite to find so that we can load them up again.

};


#endif // CLASS_H_INCLUDED
