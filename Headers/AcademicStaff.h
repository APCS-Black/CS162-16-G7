#ifndef ACADEMICSTAFF_H_INCLUDED
#define ACADEMICSTAFF_H_INCLUDED

#include "HeaderList.h"

/*

Create an g_CourseList object at the beginning of the program and call it CourseList.
Everyone will get data from that object.

I have asked for all the needed input in these function, call and use.

About import Student list, a list will be a class list, which contains student ID of everyone in that list.

The input file for Student list will be like this.

ClassName
Number of Student
Student ID
Full name
Date of birth (dd/mm/yyyy)
Phonenumber


*/

void ExportCourseScore(g_CourseList CourseList);
void ExportStudentScore(g_CourseList CourseList, ClassList c_List);
void ImportCourse(g_CourseList &CourseList, UserList uList, Check_inList checkinList, ClassList c_List);
void ImportStudent(UserList uList, ClassList c_List);


#endif // ACADEMICSTAFF_H_INCLUDED
