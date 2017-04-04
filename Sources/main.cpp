#include "../Headers/HeaderList.h"

//#include <conio.h>
//#include <windows.h>

using namespace std;

/*void gotoxy(int x, int y)

{

	COORD ord;

	ord.X = x;

	ord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);

}*/

void main()
{
	int ch;
	bool bBreak;

	bBreak = false;
	do
	{
		system("cls");
		gotoxy(10, 1);
		cout << "MAIN MENU";
		gotoxy(10, 2);
		cout << "__________________________________";
		gotoxy(10, 4);
		cout << "1.Add Record";
		gotoxy(10, 5);
		cout << "2.Delete Specify Record";
		gotoxy(10, 6);
		cout << "3.Delete All Records";
		gotoxy(10, 7);
		cout << "4.Find A Record";
		gotoxy(10, 8);
		cout << "5.Display All Records";
		gotoxy(10, 9);
		cout << "6.About Developer";
		gotoxy(10, 10);
		cout << "7.Exit";
		gotoxy(10, 11);
		cout << "Choose Number : ";
		ch = _getch();
		switch (ch)
		{
		case 27:
			bBreak = true;
			break;
		}
	} while (!bBreak);
}
