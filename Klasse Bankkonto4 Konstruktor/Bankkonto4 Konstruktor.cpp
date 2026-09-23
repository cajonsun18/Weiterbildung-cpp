#include <iostream>
#include "konto.h"
#include "kontoart.h"

int main()
{
	try
	{
		Konto konto1("Willi", "Wacker", 1234567890LL, Kontoart::Girokonto, 150.0, 2000.0);

		Konto konto2;
		cout << konto1.toString();
		cout << konto2.toString();

		konto1.WithdrawMoney(200.0);
		cout << konto1.toString();

		Konto *konto3 = new Konto();

		delete konto3;
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