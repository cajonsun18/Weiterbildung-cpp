#pragma once
#include "tier.h"
#include <string>
using namespace std;

#ifndef _HUND_H_
#define _HUND_H_

class Hund : public Tier
{
private:
	string _rasse;
public:
	// ---------- De-/Konstruktoren ----------
	~Hund() = default;

	Hund(string name, int alter, string rasse);
	Hund(string name, int alter);
	Hund(string name);
	Hund();

	// ---------- Getter ----------
	string getRasse() const { return _rasse; }
	string toString() const;
	string getLaut() const override;

	// ---------- Setter ----------
	void setRasse(string value);
};

#endif