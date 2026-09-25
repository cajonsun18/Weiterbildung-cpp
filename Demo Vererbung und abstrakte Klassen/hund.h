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
	string _futterArt;
public:
	// ---------- De-/Konstruktoren ----------
	~Hund() = default;

	Hund(string name, string farbe, int alter, string rasse);
	Hund(string name, string farbe, int alter);
	Hund(string name, string farbe);
	Hund(string name);
	Hund();

	// ---------- Getter ----------
	string getRasse() const { return _rasse; }
	string gibLaut();
	string toString() const;
	string getFutterart() const override;

	// ---------- Setter ----------
	void setRasse(string value);
	void setFutterart(string value) override;
};

#endif