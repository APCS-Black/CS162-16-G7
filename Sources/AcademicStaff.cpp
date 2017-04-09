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

void ExportStudentScore(g_CourseList CourseList, ClassList c_List){
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
    Class *in_class;
    in_class= c_List.FindClass(StudentID);
    if (check)  {
        strcpy(filepath,filename);
    } else {
        strcat(filepath,filename);
    }
    fout.open(filepath);
    fout<<StudentID<<" Score report"<<endl;
    CourseList.ExportScore(StudentID,Year,Semester,fout, in_class);
    fout.close();
}

void ImportCourse(g_CourseList &CourseList, UserList uList, Check_inList checkinList, ClassList c_List){
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
    CourseList.Import(fin, uList, checkinList,c_List);
    fin.close();
}

void ImportStudent(UserList uList, ClassList c_List){
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
    //char ClassName[10];
    int n;
    Class temp;
    fin>>temp.ClassName;
    fin>>n;

    //temp.ClassName=ClassName;
    temp.StudentCount=n;
    /*
        Here i will add a student into their class list and create a new user for them at the same time.
    */
    for (int i=0; i<n; i++){
        User newUser;
        fin>>newUser.Username;
        //int StudentID= ConvertoNum(newUser.Username); create this function for me please
        newUser.Class[0] = temp.ClassName;
        temp.s_List.AddStudent(StudentID);
        fin.ignore(2,'\n');
        fin.getline(newUser.Fullname,30,'\n');
        Date inDate;
        char dash;
        fin>>inDate.day>>dash>>inDate.month>>dash>>inDate.year;
        // create a function to set password as ddmmyyyy pleasety
        newUser.Type=0;
        uList.AddHead(newUser);

    }
    fin.close();
}
