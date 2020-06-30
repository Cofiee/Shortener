#include "UserInterface.h"

UserInterface::UserInterface()
{
}

void UserInterface::Pause()
{
	cout << "Press a KEY to continue" << endl;
	system("pause>nul");
	system("cls");
}

void UserInterface::ClearConsole()
{
	system("cls");
}

std::string UserInterface::AskLink()
{
	cout << "Podaj link do skrócenia\n>:";
	string word;
	cin >> word;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Wprowadz poprawne slowo!\n>:";
		cin >> word;
	}
	return word;
}

void UserInterface::WriteMessage(string message)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORMAT);
	cout << message << endl;
}

int UserInterface::Choose(string message, string* option, int optNumb)
{
	int answer = 0;
	while (1)
	{
		system("cls");
		WriteMessage(message);
		for (int i = 0; i < optNumb; i++)
		{
			if (i == answer) 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			else 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORMAT);
			cout << "*" << option[i] << "*" << endl;
		}
		system("pause>nul");
		if (GetAsyncKeyState(VK_DOWN) && ((optNumb - 1) != answer))
			++answer;
		if (GetAsyncKeyState(VK_UP) && (0 != answer))
			--answer;
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FORMAT);
	return answer + 1;
}


