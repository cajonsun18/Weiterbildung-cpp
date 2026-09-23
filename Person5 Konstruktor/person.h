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

public:
	// ---------- Konstruktoren ----------
	Person();
	Person(string nachname, string vorname);
	Person(string nachname, string vorname,
		string strasse, string plz, string ort);

	// ---------- Getter ----------
	string getNachname() const;
	string getVorname() const;
	string getStrasse() const;
	string getPlz() const;
	string getOrt() const;
	string toString() const;

	// ---------- Setter ----------
	bool setNachname(string value);
	bool setVorname(string value);
	bool setStrasse(string value);
	bool setPlz(string value);
	bool setOrt(string value);
};

#endif