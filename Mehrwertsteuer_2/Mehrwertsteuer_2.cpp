#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "de_DE.utf8");
	cout << setprecision(2) << fixed;

	//V)ariable
	double nettobetrag = 0, mwst_satz = 0, mwst;

	//E)ingabe
	cout << "Gebe den Nettobetrag ein:";
	cin >> nettobetrag;
	cout << "Gebe den Mehrwertsteuersatz ein (in Prozent):";
	cin >> mwst_satz;

	//Nach der Eingabe, Bildschrim loeschen
	system("cls");

	//V)erarbeitung
	mwst = nettobetrag * mwst_satz / 100;

	system("cls");

	//A)usgabe
	cout << left << setw(30) << setfill('*') << "Nettobetrag:"
		 << right << setw(10) << setfill('-') << nettobetrag << " Euro" << endl;
	
	string mwst_satz_str = to_string((int)mwst_satz) + "% Mehrwertsteuer:";
	cout << left << setw(30) << setfill('*') << mwst_satz_str
		 << right << setw(10) << setfill('-') << mwst << " Euro" << endl;

	cout << left << setw(30) << setfill('*') << "Bruttobetrag:"
		 << right << setw(10) << setfill('-') << nettobetrag + mwst << " Euro" << endl;
}