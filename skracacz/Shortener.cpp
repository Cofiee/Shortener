#include "Shortener.h"

Shortener::Shortener()
{
	dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

Shortener::Shortener(string domain)
{
	this->domain = domain;
	dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

void Shortener::SetDomain(string domain)
{
	this->domain = domain;
}

void Shortener::DO_WYWALENIA_POTEM()
{
	uI.WriteMessage("Oto wygenerowany link: " + LinkGen());
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

			break;
		default:
			break;
		}
	}
}

void Shortener::AddNewLink()
{
	string inputLink = uI.AskLink();
	string shortLink;
	if (/*TUTAJ TRZEBA DAC CHCECK LINK*/1)
	{
		
	}
	else
	{
		do
		{
			shortLink = LinkGen();
		} while (/*TUTAJ TRZEBA DAC CHCECK LINK*/1);
		uI.WriteMessage("Oto skrócony link\n" + shortLink);
	}
}



int Shortener::CheckLink(int mode, string link)
{
    handler.open("links.db", ios::in);
    string line;
	while (getline(handler, line))
	{
        
    }
    return 0;
}

string Shortener::LinkGen()
{
	string shortLink = "    ";
	for (int i = 0; i < 5; i++)
	{
		int random_number = (int)(rand() * 62 / RAND_MAX);
		shortLink[i] = dictionary[random_number];
	};
	return shortLink;
}
