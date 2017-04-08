#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "HeaderList.h"
#include <termios.h>

/*Call this menu at main.cpp after create all necessary objects and variables*/
/*Plz change the parameter of all menu functions so that it fits*/
void MenuIntro(g_CourseList &CourseList, UserList userList);

#endif