#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED

#include "HeaderList.h"

void clear_screen();/*When need to clear screen, use this function with #include<windows.h>
					or system("cls"); with #include<stdlib.h>*/
void ImportScore(g_CourseList &CourseList, User Lecturer);//Call this function when lecturer user chose the option importing score list
void UpdateLecturerClass(User* user, char Coursecode[], int Year, int Semester);
/*This function used for updating the courses list of the lecturer
				is called when a new course is created and assigned to a lecturer */

#endif
