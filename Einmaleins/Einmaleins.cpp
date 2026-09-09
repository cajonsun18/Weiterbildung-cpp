
#include <iomanip>
#include <iostream>
using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')

int main()
{
	const int LOWERLIMIT = 1;
	const int UPPERLIMIT = 20;
	int zahl = 0;
	bool invalidInput = false;

    cout << "Bitte gebe eine Zahl zwischen 1-20 ein: ";
	cin >> zahl;

	while (cin.fail() || zahl < LOWERLIMIT || zahl > UPPERLIMIT)
	{
		if (cin.fail())
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein.";
		}
		else
		{
			cout << "Es wurde keine Zahl zwischen 1-20 eingegeben. Versuchen Sie es erneut: ";
		}

		CLEAR_CIN;
		cin >> zahl;
	}

	/*do {
		invalidInput = false;

		if (cin.fail())
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
			CLEAR_CIN;
			cin >> zahl;
			invalidInput = true;
		} 
		else if (zahl < LOWERLIMIT || zahl > UPPERLIMIT) 
		{
			cout << "Es wurde keine Zahl zwischen 1-20 eingegeben. Versuchen Sie es erneut: ";
			CLEAR_CIN;
			cin >> zahl;
			invalidInput = true;
		}
	} while (invalidInput);*/

	cout << endl 
		 << "For-Schleife" << endl;

	for (int i = 1; i <= 10; i++)
	{
		int ergebnis = i * zahl;
		cout << left << setw(2) << i << " x " << zahl << " = " << right << setw(3) << ergebnis << endl;
	}

	cout << endl
		 << "While-Schleife" << endl;

	int i_while = 1;
	while (i_while <= 10) 
	{
		int ergebnis = i_while * zahl;
		cout << left << setw(2) << i_while << " x " << zahl << " = " << right << setw(3) << ergebnis << endl;

		i_while++;
	}

	cout << endl
		 << "Do-While-Schleife" << endl;

	int i_do_while = 1;
	do
	{
		int ergebnis = i_do_while * zahl;
		cout << left << setw(2) << i_do_while << " x " << zahl << " = " << right << setw(3) << ergebnis << endl;

		i_do_while++;
	} while (i_do_while <= 10);
}