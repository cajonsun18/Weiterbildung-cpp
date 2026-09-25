#pragma once
#include "fahrzeug.h"
class Motorrad : public Fahrzeug
{
private:
	int _reifenAnzahl;
public:
	// ---------- De-/Konstruktoren ----------
	~Motorrad() = default;

	Motorrad(string kennzeichen, int reifenAnzahl);
	Motorrad(string kennzeichen);
	Motorrad();

	// ---------- Getter ----------
	int getReifenanzahl() const { return _reifenAnzahl; }
	string toString() const;

	// ---------- Setter ----------
	void setReifenanzahl(int value);
};

