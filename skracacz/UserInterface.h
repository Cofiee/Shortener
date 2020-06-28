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

	void Pause(); //Metoda pauzujaca to co sie dzieje w programie i oczekujaca na aktywnosc na klawiaturze

	void ClearConsole(); //Metoda do czyszczenia zawartosci konsoli

	string AskWord(); //Metoda proszaca o slowa. Przeprowadza kontrole poprawnosci. Zwraca obiekt typu string z podanym slowem.

	void WriteMessage(string message); //Metoda wypisuje w konsoli komunikat w odpowiednim formacie.

	void WriteMessage(char* message, int lenght); //Metoda wypisuje w konsoli komunikat w odpowiednim formacie.

	int Choose(string message, string* option, int optNumb); //Metoda tworzaca liste z opcjami do wyboru.

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
