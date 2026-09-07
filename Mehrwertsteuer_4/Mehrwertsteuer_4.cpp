#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "de_DE.utf8");
	cout << setprecision(2) << fixed;

	//V)ariable
	double nettobetrag = 0, mwst_satz = 0, mwst = 0;
	char mwst_kennzeichen = ' ', laenderkennzeichen = ' ';

	//E)ingabe
	cout << "Geben sie ein Länderkennzeichen ein (I = EU-Inland, A = EU-Ausland): ";
	cin >> laenderkennzeichen;

	if (tolower(laenderkennzeichen) == 'a') 
	{
		mwst_satz = 0;
	}
	else if (tolower(laenderkennzeichen) == 'i')
	{
		cout << "Geben sie ein Mwstkennzeichen ein (E = Ermäßigt, N = Normal): ";
		cin >> mwst_kennzeichen;

		if (tolower(mwst_kennzeichen) == 'e')
		{
			mwst_satz = 7;
		}
		else if (tolower(mwst_kennzeichen) == 'n')
		{
			mwst_satz = 19;
		}
		else
		{
			cout << "Ungültige Eingabe. Bitte geben Sie ein E oder ein N ein." << endl;
			return -2;
		}
	} 
	else
	{
		cout << "Ungültige Eingabe. Bitte geben Sie ein I oder ein A ein." << endl;
		return -1;
	}


	cout << "Gebe den Nettobetrag ein: ";
	cin >> nettobetrag;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Gebe den Nettobetrag ein:";
		cin >> nettobetrag;
	}

	//Nach der Eingabe, Bildschrim loeschen
	system("cls");

	//V)erarbeitung
	mwst = nettobetrag * mwst_satz / 100;

	system("cls");

	//A)usgabe
	cout << left << setw(30) << "Nettobetrag:"
		<< right << setw(10) << nettobetrag << " Euro" << endl;

	string mwst_satz_str = to_string((int)mwst_satz) + "% Mehrwertsteuer:";
	cout << left << setw(30) << mwst_satz_str
		<< right << setw(10) << mwst << " Euro" << endl;

	cout << left << setw(30) << "Bruttobetrag:"
		<< right << setw(10) << nettobetrag + mwst << " Euro" << endl;
}