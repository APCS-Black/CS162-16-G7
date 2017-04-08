#include "../Headers/Lecture.h"

#include <iostream>
#include <windows.h>
using namespace std;

/*When need to clear screen, use this function or system("cls"); with #include<stdlib.h>*/
void clear_screen(void)
{
	DWORD n;                         /* Number of characters written */
	DWORD size;                      /* number of visible characters */
	COORD coord = { 0 };               /* Top left screen position */
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	/* Get a handle to the console */
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(h, &csbi);

	/* Find the number of characters to overwrite */
	size = csbi.dwSize.X * csbi.dwSize.Y;

	/* Overwrite the screen buffer with whitespace */
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

	/* Reset the cursor to the top left position */
	SetConsoleCursorPosition(h, coord);
}

//This function is only used for char** Class from class User
int convertCharArrtoNum(char str[])
{
	int n = str.strlen();
	if (n == 1) return ((int)str[0] - 48); //when char array is '1' to '9'
	if (n == 2) //when char array is "10" -> "99"
		return ( ((int)str[0] - 48) * 10 + ((int)str[1] - 48) );
	return NULL;
}

bool InputScoreListFile(ScoreBoard ScoreList, ifstream fin)
{
	if (!fin) return false;

	int nstudent;
	Score this_score;
	bool check = true;

	fin >> nstudent;
	for (int i = 0; i < nstudent; ++i)
	{
		fin >> this_score.StudentID;
		if (fin.fail())
		{
			check = false;
			break;
		}
		fin.get();
		fin.get(this_score.StudentName, 70, '\n');
		fin.get();
		fin >> this_score.Labscore;
		if (fin.fail())
		{
			check = false;
			break;
		}
		fin >> this_score.Midtermscore;
		if (fin.fail())
		{
			check = false;
			break;
		}
		fin >> this_score.Finalscore;
		if (fin.fail())
		{
			check = false;
			break;
		}
		ScoreList.AddFirst(this_score);
	}
	return check;
}

//Call this function when lecturer user chose the option importing score list
void ImportScore(g_CourseList &CourseList, User Lecturer)
{
	int ncourse = convertCharArrtoNum(Lecturer.Class[0]);
	//Lecturer.Class[0] stores the number of courses as char array type
	int this_year, this_semester;//Need editing
	short i, j;

	while (1)
	{
		/*Menu for importing score list*/
		cout << "Ongoing teaching courses: \n";
		for (j = 1; j <= ncourse; ++j)
		{
			cout << j << ". " << Lecturer.Class[j] << ".\n";
		}
		cout << j + 1 << ". Back.\n";
		//cout << j + 2 << ". Exit.\n"; will do it later if time left
		cout << "Choice: ";
		cin >> i;
		clear_screen();
		//------------------------------//

		if (cin.fail() || i > ncourse || i < 1)
		{
			cout << "False input!\n";
			cout << "[Press Enter to continue]";
			cin.getline();
			clear_screen();
			continue;
		}

		if (i == j + 1) return;

		g_Course* course = FindCourse(Lecturer.Class[i], this_year, this_semester);

		/*Read from the file given by user*/
		char filename[200], filepath[500] = "../Import/";
		bool check = false;
		cout << "Please enter the name input file: " << endl;
		cout << "(If no path is specified, the default search path is: /Import/name.txt" << endl;
		cout << " make sure your file is in that directory)" << endl;
		cin >> filename;
		int l = strlen(filename);
		for (int i = 0; i<l; i++) {
			if (filename[i] == '/') {
				check = true;
				break;
			}
		}
		ifstream fin;
		if (check) {
			strcpy(filepath, filename);
		}
		else {
			strcat(filepath, filename);
		}
		fin.open(filepath);
		//--------------------------------------//
		course->ScoreList.MakeUnavailable();
		course->ScoreList.Clear();
		if (InputScoreListFile(course->ScoreList, ifstream fin))
		{
			cout << "Input score list from file successfully!\n";
			course->ScoreList.MakeAvailable();
		}
		else cout << "An error has occured! Failed to input score list from file...\n";
		
		fin.close();
	}
}

//This function is only used for char** Class from class User
char* convertNumtoCharArr(int num)
{
	char* res;
	res[0] = '0';
	res[1] = '\0';
	if (num <= 9)
	{
		res[0] = (char)(num + 48);
		res[1] = '\0';
		return res;
	}
	if (num <= 99)
	{
		res[0] = (char)(num / 10 + 48);
		res[1] = (char)(num % 10 + 48);
		res[2] = '\0';
		return res;
	}
	return res;
}

/*This function used for updating the courses list of the lecturer 
is called when a new course is created and assigned to a lecturer */
void UpdateLecturerClass(User* user, char Coursecode[])
{
	int n = convertCharArrtoNum(user.Class[0]);//Convert number of lecturer's courses from char* to int
	++n;//Increasing since this lecturer has 1 more new course to teach
	strcpy(user.Class[0], convertNumtoCharArr(n));//After increasing, copy it back to the storage char array
	
	strcpy(user.Class[n], Coursecode);//Add Coursecode to the courses storage of this lecturer
}