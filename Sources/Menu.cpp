#include "../Headers/HeaderList.h"

using namespace std;

void MenuStudent(g_CourseList CourseList, User Student)
{
	short opt;
	while (1)
	{
		cout << "1. Check-in class.\n";
		cout << "2. Logout.\n";
		cout << "Choice: ";
		cin >> opt;
		clear_screen();

		if (cin.fail()) continue;

		switch (opt)
		{
		case 1: 
			break;
		case 2:
			return;
		default:
		}
	}
}

void MenuAcademicStaff(g_CourseList &CourseList, User AStaff)
{
	short opt;
	while (1)
	{
		cout << "1. Import courses.\n";
		cout << "2. Import student lists.\n";
		cout << "3. Export scores of a student.\n";
		cout << "4. Export scorelist of a course.\n";
		cout << "5. Export lists of	student	who	was	present	or absent in class.\n";
		cout << "6. Logout.\n";
		cout << "Choice: ";
		cin >> opt;
		clear_screen();

		if (cin.fail()) continue;

		switch (opt)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			return;
		default:
		}
	}
}

void MenuLecturer(g_CourseList &CourseList, User Lecturer)
{
	short opt;
	while (1)
	{
		cout << "1. Import scorelist of a course.\n";
		cout << "2. logout.\n";
		cout << "Choice: ";
		cin >> opt;
		clear_screen();

		if (cin.fail()) continue;

		switch (opt)
		{
		case 1:
			ImportScore(CourseList, Lecturer);
			break;
		case 2:
			return;
		default:
		}
	}
}

/*------------Hide password methods-------------*/
void HideStdinKeystrokes()
{
	termios tty;

	tcgetattr(STDIN_FILENO, &tty);

	/* we want to disable echo */
	tty.c_lflag &= ~ECHO;

	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void ShowStdinKeystrokes()
{
	termios tty;

	tcgetattr(STDIN_FILENO, &tty);

	/* we want to reenable echo */
	tty.c_lflag |= ECHO;

	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
//------------------------------------------------//

void MenuLogin(UserList userList)
{
	char Username[20], Password[20];
	short opt;
	
	cout << "Login Menu\n";
	cout << "Username: ";
	cin.get();
	cin.get(Username, 20, '\n');
	cin.get();
	cout << "Password: ";
	HideStdinKeystrokes();
	cin.get();
	cin.get(Password, 20, '\n');
	cin.get();
	clear_screen();
	ShowStdinKeystrokes();

	User user = userList.FindUser(Username);
	if (!user || strcmp(user->Password, Password) != 0)
	{
		cout << "*Username or password is incorrect. Please try again.\n";
		cout << "[Press Enter to continue...]";
		cin.getline();
		clear_screen();
		return;
	}
	else
	{
		cout << "Login successfully!\n";
		cout << "[Press Enter to continue...]";
		cin.getline();
		clear_screen();
		int type = user->Type;
		switch (type)
		{
		case 0:
			MenuStudent();
			return;
		case 1:
			MenuAcademicStaff();
			return;
		case 2:
			MenuLecturer();
			return;
		}
	}
}

void MenuIntro(g_CourseList &CourseList, UserList userList)
{
	cout << "Welcome to Academic Management Program\n";
	cout << "          ***CS162-Team 7***          \n";
	
	short opt;

	while (1)
	{
		cout << "Enter a number below to run the following command:\n";
		cout << "1. Login.\n";
		cout << "2. Exit.\n";
		cout << "Choice: ";
		cin >> opt;
		clear_screen();

		if (cin.fail()) continue;

		switch (opt)
		{
		case 1:
			MenuLogin();
			break;
		case 2:
			return;
		default:
		}
	}
}