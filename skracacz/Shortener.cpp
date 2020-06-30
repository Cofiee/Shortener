#include "Shortener.h"

Shortener::Shortener()
{
	fstream file(DATABASE_FILE, ios::app);
	file.close();
	dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

Shortener::Shortener(string domain)
{
	fstream file(DATABASE_FILE, ios::app);
	file.close();
	this->domain = domain;
	dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

void Shortener::SetDomain(string domain)
{
	this->domain = domain;
}

void Shortener::MainMenu()
{
	int answer = 0;
	string options[3] = {
		"Dodaj nowy link do bazy danych",
		"Wyœwietl bazê danych",
		"Opuœæ program"
	};
	while (3 != answer)
	{
		answer = uI.Choose("Program do skracania linków\n", options, 3);
		switch (answer)
		{
		case 1:
		{
			AddNewLink();
			break;
		}
		case 2:
			ShowDb();
			break;
		default:
			break;
		}
	}
}

void Shortener::AddNewLink()
{
	uI.ClearConsole();
	string inputLink = uI.AskLink();
	string shortLink;
	package result = CheckLink(inputLink);
	if (1 == result.result)
	{
		uI.WriteMessage("\nPodany link juz istnieje w bazie danych :\n" + result.link[0] + "\n" + result.link[1]);
		uI.Pause();
	}
	else
	{
		do
		{
			shortLink = LinkGen();
			result = CheckLink(this->domain + shortLink);
		} while (1 == result.result);
		ofstream file(DATABASE_FILE, ios::app);
		file << inputLink + "\t" + this->domain + shortLink + "\n";
		file.close();
		uI.WriteMessage("\nOto skrócony link :\n" + this->domain + shortLink);
		uI.Pause();
	}
}

package Shortener::CheckLink(string inputLink)
{
	package result;
	result.result = 0;
	ifstream file(DATABASE_FILE);
	string str;
	string column0;
	string column1;
	while (getline(file, str))
	{
		int i;
		for (i = 0; str[i] != '\t'; ++i);
		column0 = str.substr(0, i);
		column1 = str.substr(i+1);
		if (0 == inputLink.compare(column0) || 0 == inputLink.compare(column1))
		{
			result.result = 1;
			result.link[0] = column0;
			result.link[1] = column1;
			break;
		}
	}
	file.close();
	return result;
}

string Shortener::LinkGen()
{
	string shortLink = "    ";
	for (int i = 0; i < 5; i++)
	{
		int random = (int)(rand() * 62 / RAND_MAX);
		shortLink[i] = dictionary[random];
	};
	return shortLink;
}

void Shortener::ShowDb()
{
	uI.ClearConsole();
	ifstream file(DATABASE_FILE);
	string str;
	while (getline(file, str))
	{
		uI.WriteMessage(str);
	}
	file.close();
	uI.Pause();
}
