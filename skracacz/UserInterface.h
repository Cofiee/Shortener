#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#define FORMAT 15
using namespace std;
class UserInterface //Klasa odpowiedzialna za cala komunikacje z uzytkownikiem
{
private:
public:
	UserInterface();

	~UserInterface();

	/*Metoda pauzujaca to co sie dzieje w programie i oczekujaca na aktywnosc na klawiaturze*/
	void Pause();

	/*Metoda do czyszczenia zawartosci konsoli*/
	void ClearConsole();

	/*Metoda proszaca o link. 
	Przeprowadza kontrole poprawnosci. 
	Zwraca obiekt typu string z podanym slowem.*/
	string AskLink();

	/*Metoda wypisuje w konsoli komunikat w odpowiednim formacie.
		message - ciag znakow do wyswietlenia w konsoli
	*/
	void WriteMessage(string message);

	/*Metoda wypisuje w konsoli komunikat w odpowiednim formacie.
		message - wskaznik na tablice znakow
		lenght - dlugos tablicy "message"
	*/
	void WriteMessage(char* message, int lenght);

	/*Metoda tworzaca liste z opcjami do wyboru.
		message - wiadomosc do wyswietlenia
		option - wskaznik na tablice typu string zawierajace opcje do wyboru
		optNumb - dlugosc tablicy "option";
	*/
	int Choose(string message, string* option, int optNumb);

	template<typename T>
	void WriteArray(T arr, int lenght); //Szablon do wypisania dowolnej tablicy.
};

template<typename T>
inline void UserInterface::WriteArray(T arr, int lenght)
{
	system("cls");
	for (int i = 0; i < lenght; ++i)
		cout << arr[i] << endl;
}
