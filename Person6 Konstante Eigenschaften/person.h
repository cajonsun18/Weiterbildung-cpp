#pragma once
#include <string>
using namespace std;

#ifndef _KONTO_H_
#define _KONTO_H_

class Person
{
private:
	string _nachname;
	string _vorname;
	string _strasse;
	string _plz;
	string _ort;
	string _gebDatum;
	void setGebDatum(string value);

public:
	// ---------- Konstruktoren ----------
	Person();
	Person(string nachname, string vorname);
	Person(string nachname, string vorname,
		string strasse, string plz, 
		string ort, string gebDatum);

	// ---------- Getter ----------
	string getNachname() const;
	string getVorname() const;
	string getStrasse() const;
	string getPlz() const;
	string getOrt() const;
	string getGebDatum() const;
	string toString() const;

	// ---------- Setter ----------
	void setNachname(string value);
	void setVorname(string value);
	void setStrasse(string value);
	void setPlz(string value);
	void setOrt(string value);
};

#endif