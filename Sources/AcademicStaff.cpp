#include "../Headers/AcademicStaff.h"

void ExportCourseScore(g_CourseList CourseList){
    char filename[200];
    char CourseCode[10];
    char filepath[500] = "../Output/";
    bool check=false;
    int Year, Semester;
    cout<<"Please enter the name of the course you want to export: ";
    cin>>CourseCode;
    cout<<"Please enter the year of that course: ";
    cin>>Year;
    cout<<"Please enter the semester of that course: ";
    cin>>Semester;
    cout<<"Please enter the name of the destination file: "<<endl;
    cout<<"(If no path is specified, the default path is: /Output/name.txt)"<<endl;
    cin>>filename;
    int l=strlen(filename);
    for (int i=0; i<l; i++){
        if (filename[i]=='/') {
            check = true;
            break;
        }
    }
    ofstream fout;
    if (check)  {
        strcpy(filepath,filename);
    } else {
        strcat(filepath,filename);
    }
    fout.open(filepath);
    CourseList.ExportScore(CourseCode,Year,Semester,fout);
    fout.close();

}

void ExportStudentScore(g_CourseList CourseList){
    char filename[200],filepath[500]="../Output/";
    int StudentID;
    int Year,Semester;
    bool check=false;
    cout<<"Please enter the name of the student you want to export: ";
    cin>>StudentID;
    cout<<"Please enter the year : ";
    cin>>Year;
    cout<<"Please enter the semester: ";
    cin>>Semester;
    cout<<"Please enter the name of the destination file: "<<endl;
    cout<<"(If no path is specified, the default path is: /Output/name.txt)"<<endl;
    cin>>filename;
    int l=strlen(filename);
    for (int i=0; i<l; i++){
        if (filename[i]=='/') {
            check = true;
            break;
        }
    }
    ofstream fout;
    if (check)  {
        strcpy(filepath,filename);
    } else {
        strcat(filepath,filename);
    }
    fout.open(filepath);
    fout<<StudentID<<" Score report"<<endl;
    CourseList.ExportScore(StudentID,Year,Semester,fout);
    fout.close();
}

void ImportCourse(g_CourseList &CourseList){
    char filename[200],filepath[500]="../Import/";
    bool check = false;
    cout<<"Please enter the name input file: "<<endl;
    cout<<"(If no path is specified, the default search path is: /Import/name.txt"<<endl;
    cout<<" make sure your file is in that directory)"<<endl;
    cin>>filename;
    int l=strlen(filename);
    for (int i=0; i<l; i++){
        if (filename[i]=='/') {
            check = true;
            break;
        }
    }
    ifstream fin;
    if (check)  {
        strcpy(filepath,filename);
    } else {
        strcat(filepath,filename);
    }
    fin.open(filepath);
    CourseList.Import(fin);
    fin.close();
}
