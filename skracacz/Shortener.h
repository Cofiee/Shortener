#pragma once
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "UserInterface.h"

using namespace std;
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
		mode - wybor tybu metody:  
		0 - sprawdza czy dlugi link jest juz w bazie danych 
		1 - sprawdza czy skrocony link jest juz w bazie danych

		metoda zwraca:
			
	*/
	int CheckLink(int mode, string link);

	/*Generuje skrocone linki
		metoda zwraca ciag pieciu losowo wygenerowanych znakow
	*/
	string LinkGen();
};

