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
	string getNachname() { return _nachname; }
	string getVorname() { return _vorname; }
	string getStrasse() { return _strasse; }
	string getPlz() { return _plz; }
	string getOrt() { return _ort; }
	string toString();

	// Setter

	void setNachname(string value);
	void setVorname(string value);
	void setStrasse(string value);
	void setPlz(string value);
	void setOrt(string value);
};

#endif

