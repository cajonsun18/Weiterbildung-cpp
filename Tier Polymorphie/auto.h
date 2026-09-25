#pragma once
#include "fahrzeug.h"

#include <string>
using namespace std;

#ifndef _AUTO_H_
#define _AUTO_H_

class Auto : public Fahrzeug
{
private:
	string _dachTyp;
public:
	// ---------- De-/Konstruktoren ----------
	~Auto() = default;

	Auto(string kennzeichen, string dachTyp);
	Auto(string kennzeichen);
	Auto();

	// ---------- Getter ----------
	string getDachTyp() const { return _dachTyp; }
	string toString() const;

	// ---------- Setter ----------
	void setDachTyp(string value);
};

#endif