#include "Shortener.h"
#define MY_DOMAIN "https://www.szyb.ko/"
int main()
{
	setlocale(LC_CTYPE, "Polish");
	Shortener shortener(MY_DOMAIN);
	//shortener.MainMenu();
	shortener.DO_WYWALENIA_POTEM();
}