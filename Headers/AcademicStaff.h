#ifndef ACADEMICSTAFF_H_INCLUDED
#define ACADEMICSTAFF_H_INCLUDED

#include "HeaderList.h"

/*

Create an g_CourseList object at the beginning of the program and call it CourseList.
Everyone will get data from that object.

I have asked for all the needed input in these function, call and use.

*/

void ExportCourseScore(g_CourseList CourseList);
void ExportStudentScore(g_CourseList CourseList);
void ImportCourse(g_CourseList &CourseList);


#endif // ACADEMICSTAFF_H_INCLUDED
