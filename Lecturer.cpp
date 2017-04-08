#include "../Headers/Lecture.h"

#include <iostream>
#include <windows.h>
using namespace std;

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

void ImportScore(g_CourseList &CourseList, User Lecturer)
{
	int ncourse = (int)Lecturer.Class[0] - 48;
	int this_year, this_semester;
	short i, j;

	while (1)
	{
		cout << "Ongoing teaching courses: \n";
		for (j = 1; j <= ncourse; ++i)
		{
			cout << j << ". " << Lecturer.Class[i] << ".\n";
		}
		cout << j + 1 << ". Back.\n";
		//cout << j + 2 << ". Exit.\n";
		cout << "Choice: ";
		cin >> i;
		clear_screen();

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

		/*Read from file given by user*/
		ifstream fin;
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
		if (InputScoreListFile(course->ScoreList, ifstream fin)) cout << "Input score list from file successfully!\n";
		else cout << "An error has occured! Failed to input score list from file...\n";
		course->ScoreList.MakeAvailable();

		fin.close();
	}
}