#pragma once
#include "kontoart.h"
#include <string>

using namespace std;

#ifndef _KONTO_H_
#define _KONTO_H_

class Konto
{
private:
	string _vorname;
	string _nachname;
	long long _kontonummer = 1234567890LL;
	Kontoart _kontoart;
	double _kontostand = 0;
	double _dispo = 1000.0;
	bool setKontostand(double value);
	string kontoartToString(Kontoart kontoart);

public: 
	// Getter
	string getNachname() { return _nachname; }
	string getVorname() { return _vorname; }
	long getKontonummer() { return _kontonummer; }
	Kontoart getKontoart() { return _kontoart; }
	double getKontostand() { return _kontostand; }
	double getDispo() { return _dispo; }
	string toString();


	// Setter
	bool setNachname(string value);
	bool setVorname(string value);
	bool setKontonummer(long long value);
	bool setKontoart(Kontoart value);
	bool setDispolimit(double value);
	bool AddMoney(double value);
	bool WithdrawMoney(double value);
};

#endif

