//Name: Pham Thai Nghi
//Student ID: 1651024

#include "../Headers/HeaderList.h"

ScoreBoard::ScoreBoard(){
    head=NULL;
}

void ScoreBoard::AddFirst(Score inScore){
    ScoreNode *temp = new ScoreNode;
    temp->data = inScore;
    if (head==NULL){
        temp->next=NULL;
    } else {
        temp->next=head;
    }
    head=temp;
}

void ScoreBoard::Clear(){
    while (head){
        ScoreNode *temp= head;
        head = head ->next;
        delete temp;
    }
}

void ScoreBoard::SetCount(int n){
    nCount = n;
}

void ScoreBoard::sb_Print(ofstream &fout){
    fout<<"Student ID   Student Name    Lab     Midterm     Final"<<endl;
    ScoreNode *curr = head;
    while (curr){
        fout<<curr->data.StudentID<<" ";
        fout<<curr->data.StudentName<<" ";
        fout<<curr->data.Labscore<<" ";
        fout<<curr->data.Midtermscore<<" ";
        fout<<curr->data.Finalscore<<" "<<endl;
        curr=curr->next;
    }
}

void ScoreBoard::sb_Rewrite(ofstream &fout){
    fout<<nCount;
    ScoreNode *curr = head;
    while (curr){
        fout<<curr->data.StudentID<<endl;
        fout<<curr->data.StudentName<<endl;
        fout<<curr->data.Labscore<<" ";
        fout<<curr->data.Midtermscore<<" ";
        fout<<curr->data.Finalscore<<endl;
        curr=curr->next;
    }
}

Score ScoreBoard::sb_Find(int StudentID){
    ScoreNode *curr = head;
    while (curr){
        if (curr->data.StudentID==StudentID){
            return curr->data;
            break;
        }
    }
}

void ScoreBoard::MakeAvailable(){
    Available=true;
}

void ScoreBoard::MakeUnavailable(){
    Available=false;
}

bool ScoreBoard::isAvailable(){
    return Available;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

g_CourseList::g_CourseList(){
    head=NULL;
    tail=NULL;
    ifstream fin;
    fin.open("../Data/Courses.txt");
    fin>>nCount;
    for (int i=0; i<nCount; i++){
        g_Course temp;
        char dash;//I use this to read in format dd/mm/yyyy
        int n;//Store what ever number i need (Number of single students/scores)
        fin.ignore(2,'\n');
        fin>>temp.Coursecode;
        fin>>temp.Year;
        fin>>temp.Semester;
        fin.getline(temp.Coursename,80,'\n');
        fin>>temp.Lecturerusername;
        fin>>temp.Startat.day>>dash>>temp.Startat.month>>dash>>temp.Startat.year;
        fin>>temp.Endat.day>>dash>>temp.Endat.month>>dash>>temp.Endat.year;
        fin>>temp.From.hour>>temp.From.minute;
        fin>>temp.To.hour>>temp.To.minute;
        fin>>temp.DateOfWeek;
        fin>>temp.Class;
        fin>>n;
        temp.Singles = new int[n+1];
        temp.Singles[0]=n; // The first slot of the array will store the number, for later convenience
        for (int j=1; j<=n; j++){
            fin>>temp.Singles[j];
        }
        fin>>n;//If n==0 then the score is not yet available
        if (n>0) {
            temp.ScoreList.MakeAvailable();
            temp.ScoreList.SetCount(n);
            for (int j=0; j<n; j++){
                Score inScore;
                fin>>inScore.StudentID;
                fin.ignore(2,'\n');
                fin.getline(inScore.StudentName,70,'\n');
                fin>>inScore.Labscore>>inScore.Midtermscore>>inScore.Finalscore;
                temp.ScoreList.AddFirst(inScore);
            }
        } else {
            temp.ScoreList.MakeUnavailable();
            temp.ScoreList.SetCount(0);
        }
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


void g_CourseList::ExportScore(char Coursecode[10], int Year, int Semester, ofstream &fout){
    g_CourseNode *curr = head;
    while (curr){
        g_Course CurrCourse= curr->data;
        if ((strcmp(CurrCourse.Coursecode,Coursecode)==0)&&(CurrCourse.Year==Year)&&(CurrCourse.Semester==Semester)){
            //If it is the course we're looking for, i print it to fout.
            //Remember that courses differ by codes, year and semester.
            fout<<CurrCourse.Coursecode<<" "<<CurrCourse.Coursename<<endl;
            if (CurrCourse.ScoreList.isAvailable()){
                CurrCourse.ScoreList.sb_Print(fout);
            } else {
                fout<<"The score is not yet available, maybe the lecture have not inputed it yet"<<endl;
            }
            return ;
        }
    }
    fout<<"Course not found"<<endl;
}

void g_CourseList::ExportScore(int StudentID, int Year, int Semester, ofstream &fout){
    g_CourseNode *curr = head;
    fout<<StudentID<<" "<<Year<<" "<<Semester<<endl<<"Score Report"<<endl;
    while (curr){
        g_Course CurrCourse = curr->data;
        if ((CurrCourse.Year==Year)&&(CurrCourse.Semester==Semester)){
            int check = 0;
            //I try to check if the student is studying this course.
            //0 = no, 1= yes
            for (int i=1; i<=CurrCourse.Singles[0]; i++){
                if (CurrCourse.Singles[i]==StudentID){
                    check = 1;
                    break;
                }
            }
            int CurrClass = ((CurrCourse.Class[0]-'0')*10+(CurrCourse.Class[1]-'0'));
            //I try to take the number in class Ex 16 from 16CTT
            if ((check==0)&&(CurrClass==StudentID/100000)){
                check = 1;
            }
            //If he/she is i will go find his/her score and print them to fout.
            if (check==1){
                fout<<CurrCourse.Coursecode<<" :"<<endl;
                if (!CurrCourse.ScoreList.isAvailable()){
                    fout<<"The score is not yet availabe"<<endl;
                }else {
                    Score foundScore = CurrCourse.ScoreList.sb_Find(StudentID);
                    fout<<"Lab: "<<foundScore.Labscore<<endl;
                    fout<<"Midterm: "<<foundScore.Midtermscore<<endl;
                    fout<<"Final: "<<foundScore.Finalscore<<endl;
                }
            }

        }

    }

}

int g_CourseList::getCount(){
    return nCount;
}

void g_CourseList::Clear(){
    ofstream fout ("../Data/Courses.txt");
    fout<<nCount<<endl;
    char dash='/';
    while (head){
        g_CourseNode *temp = head;
        head= head->next;
        fout<<temp->data.Coursecode<<endl;
        fout<<temp->data.Year<<endl;
        fout<<temp->data.Semester<<endl;
        fout<<temp->data.Coursename<<endl;
        fout<<temp->data.Lecturerusername<<endl;
        fout<<temp->data.Startat.day<<dash<<temp->data.Startat.month<<dash<<temp->data.Startat.year<<endl;
        fout<<temp->data.Endat.day<<dash<<temp->data.Endat.month<<dash<<temp->data.Endat.year<<endl;
        fout<<temp->data.From.hour<<" "<<temp->data.From.minute<<endl;
        fout<<temp->data.To.hour<<" "<<temp->data.To.minute<<endl;
        fout<<temp->data.DateOfWeek<<endl;
        fout<<temp->data.Class;
        fout<<temp->data.Singles[0];
        for (int j=1; j<=temp->data.Singles[0]; j++){
            fout<<temp->data.Singles[j]<<" ";
        }
        fout<<endl;
        temp->data.ScoreList.sb_Rewrite(fout);
        delete [] temp->data.Singles;
        temp->data.ScoreList.Clear();
        delete temp;
    }
}

void g_CourseList::Import(ifstream &fin){
        g_Course temp;
        char dash;//I use this to read in format dd/mm/yyyy
        int n;//Store what ever number i need (Number of single students/scores)
        fin.ignore(2,'\n');
        fin>>temp.Coursecode;
        fin>>temp.Year;
        fin>>temp.Semester;
        fin.getline(temp.Coursename,80,'\n');
        fin>>temp.Lecturerusername;
        fin>>temp.Startat.day>>dash>>temp.Startat.month>>dash>>temp.Startat.year;
        fin>>temp.Endat.day>>dash>>temp.Endat.month>>dash>>temp.Endat.year;
        fin>>temp.From.hour>>temp.From.minute;
        fin>>temp.To.hour>>temp.To.minute;
        fin>>temp.DateOfWeek;
        fin>>temp.Class;
        fin>>n;
        temp.Singles = new int[n+1];
        temp.Singles[0]=n; // The first slot of the array will store the number, for later convenience
        for (int j=1; j<=n; j++){
            fin>>temp.Singles[j];
        }
        temp.ScoreList.MakeUnavailable();
        nCount++;
        AddLast(temp);
}

g_Course *g_CourseList::FindCourse(char CourseCode[10], int Year, int Semester){
    g_CourseNode *curr= head;
    while (curr){
            g_Course *CurrCourse = &curr->data;
            if ((strcmp(CurrCourse->Coursecode,CourseCode)==0)&&(CurrCourse->Year==Year)&&(CurrCourse->Semester==Semester)){
                return CurrCourse;
            }
    }
    return NULL;
}
