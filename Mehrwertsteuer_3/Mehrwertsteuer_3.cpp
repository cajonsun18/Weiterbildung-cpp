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
	char mwst_kennzeichen = ' ';

	//E)ingabe
	cout << "Gebe den Nettobetrag ein:";
	cin >> nettobetrag;

	if (cin.fail())
	{
		cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Gebe den Nettobetrag ein:";
		cin >> nettobetrag;
	}

	cout << "Gebe den Mehrwertsteuersatz ein (in Prozent):";
	cin >> mwst_satz;
	cout << "Gebe ein Mehrwertsteuerkennzeichen ein:";
	cin >> mwst_kennzeichen;

	//Nach der Eingabe, Bildschrim loeschen
	system("cls");

	mwst_satz = (mwst_kennzeichen == 'e') ? 7 : 19;
	/*if (mwst_kennzeichen == 'e')
	{
		mwst_satz = 7;
	} else
	{
		mwst_satz = 19;
	}*/

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