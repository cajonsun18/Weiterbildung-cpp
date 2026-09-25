#pragma once
#include "hund.h"

#ifndef _ASSISTENZTIER_H_
#define _ASSISTENZTIER_H_

class Assistenzhund : public Hund
{
private:
	string _spezialisierung;

public:
	// ---------- De-/Konstruktoren ----------
	~Assistenzhund() = default;

	Assistenzhund(string name, string farbe, int alter, string rasse, string spezialisierung);
	Assistenzhund(string name, string farbe, int alter, string rasse);
	Assistenzhund(string name, string farbe, int alter);
	Assistenzhund(string name, string farbe);
	Assistenzhund(string name);
	Assistenzhund();

	// ---------- Getter ----------
	string getSpezialisierung() const { return _spezialisierung; }
	string toString() const;

	// ---------- Setter ----------
	void setSpezialisierung(const string &value);

};

#endif