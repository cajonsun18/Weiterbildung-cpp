#pragma once
#include <string>
using namespace std;

#ifndef _FAHRZEUG_H_
#define _FAHRZEUG_H_

class Fahrzeug
{
private:
	string _kennzeichen;
public:
	// ---------- De-/Konstruktoren ----------
	~Fahrzeug() = default;

	Fahrzeug(string kennzeichen);
	Fahrzeug();

	// ---------- Getter ----------
	string getKennzeichen() const { return _kennzeichen; }
	string toString() const;

	// ---------- Setter ----------
	void setKennzeichen(string value);
};

#endif