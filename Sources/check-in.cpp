//1651072
// Tran Nguyen Son Thanh
#include"../Headers/HeaderList.h"
Check_inList::Check_inList(g_CourseList CourseList)
{
    head=NULL;
    tail=NULL;
    ifstream fin("student.txt");
	while(!fin.eof())
	{
		presence temp;
		//fin.ignore(2,'\n'); studentID is an integer so we don't need to ignore
		fin>>temp.studentid;
		fin>>temp.Coursecode; //Here Course code does not include space so fin is enough.
		fin>>temp.year;
		fin>>temp.semester;
		g_Course *foundCourse = CourseList.FindCourse(temp.Coursecode,temp.year,temp.semester); //find such course in the passed in list.
		if (foundCourse != NULL) {
            int numberOf_week = count_numberofWeek(foundCourse);
            for (int i=0; i<numberOf_week; i++){
                fin>>temp.week[i];
            }
		}
		AddLast(temp);
	}
}
void Check_inList::AddLast(presence inpresence)
{
	presenceNode *temp=new presenceNode;
	temp->data= inpresence;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		tail->next=temp;
		tail=temp;
	}
}
void Check_inList::checkIn(long student_id, g_CourseList CourseList)
{
	while(head!=NULL)
	{
		if(head->data.studentid==student_id)
		{
			time_t now=time(0);
			tm *ltm = localtime(&now);
			tm date;
			tm dateEnd;
			double standard_seconds;
			double compare_seconds;
			g_Course *foundCourse = CourseList.FindCourse(head->data.Coursecode,head->data.year,head->data.semester); //find such course in passed in List (the list all program use);
			if ((foundCourse != NULL)&&(ltm->tm_wday==foundCourse->DateOfWeek)) {
                date=*localtime(&now);
						date.tm_hour=0;
						date.tm_min=0;
						date.tm_sec=0;
						date.tm_mon=foundCourse->Startat.month;
						date.tm_year=foundCourse->Startat.year;
						date.tm_mday=foundCourse->Startat.day;
						dateEnd.tm_hour=23;
						dateEnd.tm_min=59;
						dateEnd.tm_sec=59;
						dateEnd.tm_mon=foundCourse->Endat.month;
						dateEnd.tm_year=foundCourse->Endat.year;
						dateEnd.tm_mday=foundCourse->Endat.day;
						standard_seconds=difftime(mktime(&date),mktime(&dateEnd));
						compare_seconds=difftime(mktime(&date),now);
						if((ltm->tm_hour*60+ltm->tm_min > ((foundCourse->From.hour*60)+foundCourse->From.minute))&&(ltm->tm_hour*60+ltm->tm_min< ((foundCourse->To.hour*60)+foundCourse->To.minute))&&(compare_seconds<standard_seconds))

						{
							int week_count=compare_seconds/604800+1;
							head->data.week[week_count]=1;
						}
					}
			}

	head=head->next;
	}
}

void Check_inList::export_file(g_CourseList CourseList)
{
	ofstream fout("student.txt");
			int numberofWeek;
	while(head!=NULL)
	{
	    g_Course *foundCourse = CourseList.FindCourse(head->data.Coursecode,head->data.year,head->data.semester);
	    if (foundCourse != NULL){
            numberofWeek=count_numberofWeek(foundCourse);
	    }
		fout<<head->data.studentid<<endl;
		fout<<head->data.Coursecode<<endl;
		for(int i=0;i<numberofWeek;i++)
		{
			cout<<head->data.week[i];
		}
	}
}
int Check_inList::count_numberofWeek(g_Course *Course)
{
	int number_ofWeek;
	time_t now=time(0);
	tm *ltm = localtime(&now);
	tm date;
	tm dateEnd;
	date.tm_mon=Course->Startat.month;
	date.tm_year=Course->Startat.year;
	date.tm_mday=Course->Startat.day;
	dateEnd.tm_mon=Course->Endat.month;
	dateEnd.tm_year=Course->Endat.year;
	dateEnd.tm_mday=Course->Endat.day;
	double seconds;
	seconds=difftime(mktime(&date),mktime(&dateEnd));
	number_ofWeek=seconds/86400+1;
	return number_ofWeek;
}
