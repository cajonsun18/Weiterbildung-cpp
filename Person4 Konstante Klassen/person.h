#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef _PERSON_H_
#define _PERSON_H_

class Person
{
private:
	string _nachname;
	string _vorname;
	string _strasse;
	string _plz;
	string _ort;

public:
	// Getter
	string getNachname() const { return _nachname; }
	string getVorname() const { return _vorname; }
	string getStrasse() const { return _strasse; }
	string getPlz() const { return _plz; }
	string getOrt() const { return _ort; }
	string toString() const;

	// Setter

	void setNachname(string value);
	void setVorname(string value);
	void setStrasse(string value);
	void setPlz(string value);
	void setOrt(string value);
};

#endif

