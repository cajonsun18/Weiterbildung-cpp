#include "MyLib.h"
#include <iostream>
#include <random>

using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')

void init() 
{
	srand((unsigned)time(NULL));
}

int random(int min, int max)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> i_bereich(min, max);
	return i_bereich(generator);
}

double random(double min, double max)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_real_distribution<> d_bereich(min, max);
	return d_bereich(generator);
}

int getIntZahl(string msg, int min, int max)
{
	return (int)getDblZahl(msg, min, max);
}

double getDblZahl(string msg, double min, double max)
{
	setlocale(LC_ALL, "de_DE.utf8");
	double zahl = 0;
	bool invalidInput = true;

	while (invalidInput)
	{
		invalidInput = false;

		cout << msg << endl;
		cin >> zahl;

		// Fehlerhafte Eingabe
		if (cin.fail())
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;

			CLEAR_CIN;
			invalidInput = true;
		}
		else if ((zahl < min || zahl > max)) // Zahl nicht im Bereich
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl im Bereich [" << min << "-" << max << "] ein" << endl;

			CLEAR_CIN;
			invalidInput = true;
		}
	}

	return zahl;
}
