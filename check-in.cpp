//1651072
// Tran Nguyen Son Thanh
#include"check-in.h"
Check_inList::Check_inList()
{
    head=NULL;
    tail=NULL;
    ifstream fin("student.txt");
	while(!fin.eof())
	{
		presence temp;
		fin.ignore(2,'\n');
		fin>>temp.studentid;
		fin.getline(temp.Coursecode,10,'\n');
		while(phead!=NULL)
		{
			if(strcmp(temp.Coursecode,phead->data.Coursecode)==0)
			{
				int numberOf_week=Check_inList.count_numberofWeek();
				for(int i=0;i<numberOf_week;i++)
				{
					fin>>temp.week[i];
				}
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
void Check_inList::checkIn(long student_id)
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
			while(phead!=NULL)
			{
				while(head!=NULL)
				{
					if((strcmp(head->data.Coursecode,phead->data.Coursecode)==0)&&(ltm->tm_wday==phead->data.DateOfWeek))
					{
						date=*localtime(&now);
						date.tm_hour=0;
						date.tm_min=0;
						date.tm_sec=0;
						date.tm_mon=phead->data.Startat.month;
						date.tm_year=phead->data.Startat.year;
						date.tm_mday=phead->data.Startat.day;
						dateEnd.tm_hour=23;
						dateEnd.tm_min=59;
						dateEnd.tm_sec=59;
						dateEnd.tm_mon=phead->data.Endat.month;
						dateEnd.tm_year=phead->data.Endat.year;
						dateEnd.tm_mday=phead->data.Endat.day;
						standard_seconds=difftime(mktime(&date),mktime(&dateEnd));
						compare_seconds=difftime(mktime(&date),now);
						if((ltm->tm_hour*60+ltm->tm_min > ((phead->data.From.hour*60)+phead->data.From.minute))&&(ltm->tm_hour*60+ltm->tm_min< ((phead->data.To.hour*60)+phead->data.To.minute))&&(compare_seconds<standard_seconds))

						{
							int week_count=compare_seconds/604800+1;
							head->data.week[week_count]=1;
						}
					}
					head=head->next;
				}
				
				phead=phead->next;
			}
		}
	}
	head=head->next;

}

void Check_inList::export_file()
{
	ofstream fout("student.txt");        
	while(head!=NULL)
		int numberofWeek;
	{	while(phead!=NULL)
		{
			if(strcmp(phead->data.Coursecode,head->data.Coursecode)==0)
			{
				numberofWeek=Check_inList.count_numberofWeek();
				break;
			}
			phead=phead->next
		}
		fout<<head->data.studentid<<endl;
		fout<<head->data.Coursecode<<endl;
		for(int i=0;i<numberofWeek;i++)
		{
			cout<<head->data.week[i];
		}
	}
}
int Check_inList::count_numberofWeek()
{
	int number_ofWeek;
	time_t now=time(0);
	tm *ltm = localtime(&now);
	tm date;
	tm dateEnd;	
	date.tm_mon=phead->data.Startat.month;
	date.tm_year=phead->data.Startat.year;
	date.tm_mday=phead->data.Startat.day;
	dateEnd.tm_mon=phead->data.Endat.month;
	dateEnd.tm_year=phead->data.Endat.year;
	dateEnd.tm_mday=phead->data.Endat.day;
	double seconds;
	seconds=difftime(mktime(&date),mktime(&dateEnd));
	number_ofWeek=seconds/86400+1;
	return number_ofWeek;
}
