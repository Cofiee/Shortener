#pragma once
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "UserInterface.h"
#define DATABASE_FILE "database.txt"
using namespace std;

struct package
{
	int result;
	string link[2];
};

class Shortener
{
private:
	fstream handler;
	string dictionary;
	string domain;
	UserInterface uI;
	//ifstream links;
public:
	/*Konstruktor domyslny*/
	Shortener();

	/*Konstruktor z domena
		domain - tutaj nalezy podac swoja domene
	*/
	Shortener(string domain);

	/*Metoda ustawiajaca domene
		domain - tutaj nalezy podac swoja domene
	*/
	void SetDomain(string domain);

	void DO_WYWALENIA_POTEM();

	/*Metoda odpowiadajaca za logiczna czesc menu glownego*/
	void MainMenu();

	/*Metoda */
	void AddNewLink();

	/*Metoda sprawdzajaca czy podany link znajduje sie juz w bazie danych
		metoda zwraca:
			package:
				result  0 - jezli link nie byl wprowadzony do bazy danych; 1 - jezeli znajdzie podany link w bazie danych;
				link[0] - dlugi link w bazie danych
				link[1] - krotki link w bazie danych

	*/
	package CheckLink(string link);

	/*Generuje skrocone linki
		metoda zwraca ciag pieciu losowo wygenerowanych znakow
	*/
	string LinkGen();
};

