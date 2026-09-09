#include <iostream>
using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')

int main()
{
	const int LOWERLIMIT = 1;
	const int UPPERLIMIT = 20;

	int zeilen = 0,
		maxsternchen = 0,
		leerzeichen_insgesamt = 0,
		leerzeichen_links = 0,
		sternchen_in_dieser_zeile = 0,
		stamm = 0;

	bool invalidInput = false;

	do {
		cout << "Bitte gebe die Anzahl der Zeilen ein [1-20]: ";
		cin >> zeilen;

		invalidInput = false;

		if (cin.fail() || zeilen < LOWERLIMIT || zeilen > UPPERLIMIT)
		{
			if (cin.fail())
			{
				cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
			}
			else
			{
				cout << "Es wurde keine Zahl zwischen 1-20 eingegeben. Versuchen Sie es erneut." << endl;
			}
			invalidInput = true;
			CLEAR_CIN;
		}
	} while (invalidInput);



	// Berechnet die maximale Anzahl an Sternchen in einer Zeile
	maxsternchen = 2 * zeilen - 1;

	for (int i = 1; i <= zeilen; i++)
	{
		// Berechnet die sternchen pro Zeile
		if (i <= zeilen) {
			sternchen_in_dieser_zeile = (2 * (i - 1)) + 1;
		} 

		// Berechnung der leerzeichen
		leerzeichen_insgesamt = maxsternchen - sternchen_in_dieser_zeile;
		leerzeichen_links = leerzeichen_insgesamt / 2;

		for (int k = 0; k < maxsternchen; k++)
		{
			if (k < leerzeichen_links) {
				cout << " ";
			}
			else if (k >= leerzeichen_links && k < leerzeichen_links + sternchen_in_dieser_zeile)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	// Stamm Berechnung
	if (zeilen < 4) 
	{
		stamm = 1;
	}
	else
	{
		stamm = zeilen / 4;
	}

	//cout << " Stamm: " + stamm << endl;

	for (int i = 1; i <= stamm; i++)
	{
		for (int j = 1; j < zeilen; j++)
		{
			cout << " ";
		}

		cout << "*" << endl;
	}
}

