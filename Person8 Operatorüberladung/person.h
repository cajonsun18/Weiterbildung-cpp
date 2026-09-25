#pragma once
#include <string>
#include "adresse.h"
using namespace std;

#ifndef _KONTO_H_
#define _KONTO_H_

class Person
{
private:
	string _nachname;
	string _vorname;
	string _gebDatum;
	Adresse* _adresse = nullptr;
	void setGebDatum(string value);

public:
	// ---------- Konstruktoren ----------
	~Person();
	
	Person();
	Person(string nachname, string vorname);
	Person(string nachname, string vorname,
		string adressart, string strasse,
		string hausnr, string plz,
		string ort, string gebDatum);
	Person(const Person& person);

	// ---------- Getter ----------
	string getNachname() const;
	string getVorname() const;
	string getAdressArt() const;
	string getStrasse() const;
	string getHausNr() const;
	string getPlz() const;
	string getOrt() const;
	string getGebDatum() const;
	Adresse* getAdresse() { return _adresse; };
	string toString() const;

	// ---------- Setter ----------
	void setNachname(string value);
	void setVorname(string value);

	// ---------- Operatorüberladungen ----------
	Person operator=(const Person& person);
	friend ostream& operator << (ostream &COUT, const Person &p);
};

#endif