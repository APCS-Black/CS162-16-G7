//Name: Pham Thai Nghi
//Student ID: 1651024

#include "../Headers/HeaderList.h"

g_CourseList::g_CourseList(){
    head=NULL;
    tail=NULL;
    ifstream fin;
    fin.open("../Data/Courses.txt");
    fin>>nCount;
    for (int i=0; i<nCount; i++){
        g_Course temp;
        char dash;//I use this to read in format dd/mm/yyyy
        fin.ignore(2,'\n');
        fin>>temp.Coursecode;
        fin>>temp.Year;
        fin>>temp.Semester;
        fin.getline(temp.Coursename,80,'\n');
        fin>>temp.Lecturerusername;
        fin>>temp.Startat.day>>dash>>temp.Startat.month>>dash>>temp.Startat.year;
        fin>>temp.Endat.day>>dash>>temp.Endat.month>>dash>>temp.Endat.year;
        fin>>temp.From>>temp.To;
        fin>>temp.Class;

        AddLast(temp);
    }
}

void g_CourseList::AddLast(g_Course inCourse){
    g_CourseNode *temp =new g_CourseNode;
    temp ->data = inCourse;
    temp->next=NULL;
    if (head==NULL){
        head=temp;
        tail=temp;
    } else {
        tail->next=temp;
        tail=temp;
    }
}
