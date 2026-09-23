#include <iostream>
#include "konto.h"
#include "kontoart.h"

int main()
{
	try
	{
		Konto konto1;
		konto1.setNachname("Wacker");
		konto1.setVorname("Willi");
		konto1.setKontonummer(3428937185LL);
		konto1.setKontoart(Kontoart::Girokonto);
		konto1.setDispolimit(2000.0);
		konto1.AddMoney(200.0);
		cout << konto1.toString();

		konto1.WithdrawMoney(3000.0);
		cout << konto1.toString();
	}
	catch (exception e)
	{
		cout << "Fehler: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Allgemeiner nicht lokalisierbarer Fehler" << endl;
	}
}