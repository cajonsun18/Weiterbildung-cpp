
#include <iomanip>
#include <iostream>
using namespace std;

#define CLEAR_CIN cin.clear(); cin.ignore(1000, '\n')

int main()
{
	const int TUERMCHEN_PRO_ZEILE = 7;
	const int BERECHNUNGEN_PRO_ZEILE = 14;
	int tuermchen = 0,
		zeilen = 0;
	bool invalidInput = false;

	do {
		invalidInput = false;

		cout << "Bitte gebe eine Zahl zwischen 1-20 ein: ";
		cin >> tuermchen;

		if (cin.fail())
		{
			cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
			CLEAR_CIN;
			invalidInput = true;
		}
	} while (invalidInput);

	// Berechnung der einzelnen Zeilen
	zeilen = (tuermchen / TUERMCHEN_PRO_ZEILE) + 1;


	// Anzahl der Zeilen
	for (int zeile = 0; zeile < zeilen; zeile++)
	{

		// Berechnungen pro Zeile
		for (int i = 1; i <= BERECHNUNGEN_PRO_ZEILE; i++)
		{ 
			int k = 1 + (zeile * TUERMCHEN_PRO_ZEILE);
			int k_max = TUERMCHEN_PRO_ZEILE + (zeile * TUERMCHEN_PRO_ZEILE);

			if (k_max > tuermchen) {
				k_max = tuermchen;
			}

			// Türmchen pro Zeile 
			for (; k <= k_max; k++)
			{
				int ergebnis = i * k;
				cout << left << setw(2) << i << " x " << k << " =" << right << setw(4) << ergebnis << "\t";
			}

			cout << endl;
		}

		cout << endl;
	}

	
}