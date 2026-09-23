#include <iostream>
#include "konto.h"
#include "kontoart.h"

int main()
{
	Konto konto1;
	cout << ((konto1.setNachname("Wacker")) ? "Nachname vergeben" : "Falsche Eingabe beim Nachnamen") << endl;
	cout << ((konto1.setVorname("Willi")) ? "Vorname vergeben" : "Falsche Eingabe beim Vornamen") << endl;
	cout << ((konto1.setKontonummer(3428937185LL)) ? "Kontonummer vergeben" : "Falsche Eingabe bei der Kontonummer") << endl;
	konto1.setKontoart(Kontoart::Girokonto);
	konto1.setDispolimit(2000.0);
	konto1.AddMoney(200.0);
	cout << konto1.toString();

	cout << "Versuch 3000 Euro abzuheben" << endl;
	cout << ((konto1.WithdrawMoney(3000.0)) ? "Geld erfolgreich ausgezahlt" : "Du kannst nicht ueber dein Dispo gehen.") << endl;

	cout << "Versuch 400 Euro abzuheben" << endl;
	konto1.WithdrawMoney(400.0);
	cout << ((konto1.WithdrawMoney(3000.0)) ? "Geld erfolgreich ausgezahlt" : "Du kannst nicht ueber dein Dispo gehen.") << endl;
	cout << konto1.toString();
}