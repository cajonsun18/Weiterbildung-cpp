#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "de_DE.utf8");

	double nettobetrag = 0, mwst_satz = 0, mwst;


	cout << "Gebe den Nettobetrag ein:";
	cin >> nettobetrag;

	cout << "Gebe den Mehrwertsteuersatz ein (in Prozent):";
	cin >> mwst_satz;

	mwst = nettobetrag * mwst_satz / 100;

	system("cls");

	cout << "Nettobetrag: " << nettobetrag << " Euro" << endl;
	cout << mwst_satz << " % Mehrwertsteuer: " << mwst << " Euro" << endl;
	cout << "Bruttobetrag: " << nettobetrag + mwst << " Euro" << endl; 
}