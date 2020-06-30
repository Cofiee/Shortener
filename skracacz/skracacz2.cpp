///*
#include <iostream>
#include <string>
//#include <regex>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;

//definiujemy poprawn¹ formê adresu strony internetowej, nie zadzia³a bez c++11
//static const regex addressRegex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)");
//definiujemy s³owniczek do generowania skróconych linków
static const char charArr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//definiujemy domenê naszej strony internetowej
static const string address = "https://www.krotko.edu.pl/";

//funkcja do sprawdzania czy link zosta³ wczeœniej skrócony czy nie, oraz czy skrócony link ju¿ przypadkiem nie istnieje. type = 0 - sprawdzanie d³ugiego linku, type = 1 - sprawdzanie krótkiego linku (Funkcjonalnoœæ weryfikuj¹ca)
int checkLink(int type, string link)
{
    //Otwieramy plik z baz¹ danych
    ifstream database("links.db");
    //Tworzymy zmienn¹ do przechowywania aktualnie sprawdzanej linii w bazie danych
    string dbContent;
    while (getline(database, dbContent))
    {
        if (dbContent.find(link) != string::npos)
        {
            if (type == 0)
            {
                //zamieniamy stringa na stream w celu podzielenia go na dwa oddzielne linki do wygodnego wyœwietlania
                stringstream ss(dbContent);
                string bufor;
                vector<string> links;
                while (getline(ss, bufor, ' '))
                {
                    links.push_back(bufor);
                }
                cout << "Podany link ju¿ istnieje w bazie danych:" << endl;
                cout << links[0] << endl;
                cout << links[1] << endl;
                //w przypadku, gdy d³ugi link ju¿ zosta³ skrócony to przerywamy dzia³anie programu po wyœwietleniu obu w konsoli
                exit(0);
            }
            else
            {
                //w przypadku sprawdzania skróconego linku zwracamy wartoœæ jeden, powtarzaj¹c pêtlê tworz¹c¹ link
                return 1;
            }
        }
    }
    //potwierdzamy funkcji tworz¹cej link, ¿e taki jeszcze nie istnieje
    return 0;
}

//Funkcja generuj¹ca linki na podstawie s³owniczka (Funkcjonalnoœæ Skracania)
string linkGen()
{
    //inicjujemy zmienn¹ potwierdzaj¹c¹, ¿e dany link jeszcze nie istnieje
    int result = 1;
    string shortenedLink;
    //inicjujemy pêtlê dzia³aj¹c¹ dopóki nie dostaniemy potwierdzenia, ¿e dany link jeszcze nie istnieje
    while (result != 0)
    {
        shortenedLink = address;
        //seedujemy zmienn¹ rand za pomoc¹ czasu, wiêc liczby losowe bêd¹ rzeczywiœcie losowe
        srand(time(NULL));
        for (int i = 0; i < 5; i++)
        {
            shortenedLink += charArr[rand() % 62];
        }
        //sprawdzamy czy utworzony przez nas link ju¿ nie istnieje
        result = checkLink(1, shortenedLink);
    }
    return shortenedLink;
}

//Funckja operuj¹ca na linkach. Sprawdza czy link rzeczywiœcie jest linkiem, jak tak, to tworzy ukrócony link.
void linkHandler(string link)
{
    //Sprawdzamy czy podany argument startowy to link do strony WWW
//  if(regex_match (link, addressRegex)){
        //sprawdzamy czy link zosta³ wczeœniej dodany do bazy danych za pomoc¹ funkcji checkLink
    checkLink(0, link);
    //Tworzymy link do strony za pomoc¹ funckji linkGen();
    string shortenedLink = linkGen();
    //otwieramy plik bazy w trybie append, dodawania
    fstream database("links.db", fstream::app);
    //dopisujemy link podstawowy i skrócony oddalony spacj¹
    database << link << " " << shortenedLink << endl;
    cout << "Dodano wpis do bazy danych" << endl;
    cout << "Oto skrócony link: " << shortenedLink << endl; //funkcjonalnoœc zwracaj¹ca
}
//  else{
//      cout << "Podano niepoprawny adres strony internetowej" << endl;
//  }
//}

void help()
{
    cout << "\t-l <link> - Skraca podany link i dodaje do bazy danych. W przypadku, gdy dany link ju¿ zosta³ skrócony to podaje istniej¹cy skrócony link" << endl;
    cout << "\t-db - wyœwietla pe³n¹ bazê danych linków" << endl;
    cout << "\t-h - wyœwietla t¹ stronê pomocy" << endl;
    exit(0);
}

void showDB()
{
    fstream database("links.db");
    string dbContent;
    int dbLine = 0;
    while (getline(database, dbContent))
    {
        dbLine++;
        //zamieniamy stringa na stream w celu podzielenia go na dwa oddzielne linki do wygodnego wyœwietlania
        stringstream ss(dbContent);
        string bufor;
        vector<string> links;
        while (getline(ss, bufor, ' '))
        {
            links.push_back(bufor);
        }
        cout << dbLine << ". Krótki link: " << links[1] << " D³ugi link: " << links[0] << endl;
    }
}

void mainMenu()
{
    cout << "\tWitaj w programie skracaj¹cym linki krotko.edu.pl!" << endl;
    cout << "\tCo chcesz zrobiæ?" << endl;
    cout << "\t1. Dodaj nowy link do bazy danych" << endl;
    cout << "\t2. Wyœwietl bazê danych" << endl;
    cout << "\t3. Opuœæ program" << endl;
    int mode;
    cout << "\nWybierz opcjê: ";
    cin >> mode;
    switch (mode)
    {
    case 1:
    { //musimy obj¹æ ten blok kodu w nawiasy ze wzglêdu na inicjalizacjê zmiennej
        string longLink;
        cout << "Podaj adres strony do skrócenia: ";
        cin >> longLink;
        linkHandler(longLink);
        mainMenu();
        break;
    }
    case 2:
        showDB();
        mainMenu();
        break;
    case 3:
        exit(0);
    default:
        mainMenu();
        break;
    }
}

int main(int argc, char** argv)
{
    //Ustawiamy wyœwietlanie polskich znaków.
    setlocale(LC_ALL, "");
    //Sprawdzamy czy zosta³ przekazany argument startowy
    if (argc > 1)
    {
        if (strcmp(argv[1], "-l") == 0)
        {
            linkHandler(argv[2]);
        }
        else if (strcmp(argv[1], "-db") == 0)
        {
            showDB();
        }
        else if (strcmp(argv[1], "-h") == 0)
        {
            help();
        }
        else
        {
            cout << "\tPodano niepoprawny argument!" << endl;
            help();
        }
    }
    else
    {
        mainMenu();
    }
    system("pause");
    return 0;
}
//*/