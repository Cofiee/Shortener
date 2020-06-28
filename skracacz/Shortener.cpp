#include "Shortener.h"

Shortener::Shortener()
{
	handler.open("links.db", ios::in);
	dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

void Shortener::MainMenu()
{
	int answer = 0;
	string options[3] = {
		"Dodaj nowy link do bazy danych",
		"Wyœwietl bazê danych",
		"Opóœæ program"
	};
	while (3 != answer)
	{
		answer = uI.Choose("Program do skracania linków\n", options, 3);
	}
}
