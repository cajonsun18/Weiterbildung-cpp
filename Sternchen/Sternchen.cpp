#include <iostream>
using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')

int main()
{
	const int LOWERLIMIT = 1;
	const int UPPERLIMIT = 20;

	int zahl = 0;
	bool invalidInput = false;

	do {
		cout << "Bitte gebe die Anzahl der Zeilen ein [1-20]: ";
		cin >> zahl;

		invalidInput = false;

		if (cin.fail() || zahl < LOWERLIMIT || zahl > UPPERLIMIT)
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

	for (int i = 0; i <= zahl; i++)
	{
		for (int k = 0; k < i; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

