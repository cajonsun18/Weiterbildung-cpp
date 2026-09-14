#include "funktionen.h"
#include "makros.h"

#include <random>
#include <iostream> 

int consoleEingabe(string text) 
{
	int zahl;
	bool invalidInput = true;

	while (invalidInput)
	{
		invalidInput = false;

		cout << text << ": ";
		cin >> zahl;

		// Fehlerhafte Eingabe
		if (cin.fail())
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;

			CLEAR_CIN;
			invalidInput = true;
		}
	}

	return zahl;
}

// Generiert eine Zufallszahl
int generiereZufallszahl()
{
	srand((unsigned)time(NULL));
	return rand();
}

// Generiert eine Zufallszahl zwischen 0 und max
int generiereZufallszahl(int max)
{
	return generiereZufallszahl(0, max);
}

// Generiert eine Zufallszahl zwischen min und max
int generiereZufallszahl(int min, int max)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> i_bereich(min, max);
	return i_bereich(generator);
}

void ausgabe(int zufallszahl1, int zufallszahl2, int zufallszahl3) 
{
	cout << "Die Zufallszahlen lauten: " << endl
		 << "Zufallszahl 1: " << zufallszahl1 << endl
		 << "Zufallszahl 2: " << zufallszahl2 << endl
		 << "Zufallszahl 3: " << zufallszahl3 << endl;
}