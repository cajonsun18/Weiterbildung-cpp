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
	void setKontostand(double value);
	void setKontonummer(long long value);
	string kontoartToString(Kontoart kontoart);

public:
	// Getter
	Konto();
	Konto(const string& vorname, const string& nachname, long long kontonummer, Kontoart kontoart, double kontostand, double dispo);
	~Konto();
	string getNachname() { return _nachname; }
	string getVorname() { return _vorname; }
	long getKontonummer() { return _kontonummer; }
	Kontoart getKontoart() { return _kontoart; }
	double getKontostand() { return _kontostand; }
	double getDispo() { return _dispo; }
	string toString();

	// Setter
	void setNachname(string value);
	void setVorname(string value);
	void setKontoart(Kontoart value);
	void setDispolimit(double value);
	void AddMoney(double value);
	void WithdrawMoney(double value);
	void logKontodata();
};

#endif

