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
	UserInterface uI;
	//ifstream links;
public:
	Shortener();
	void MainMenu();
};

