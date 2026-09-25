#pragma once
#include "tier.h"
class Schwein : public Tier
{
private:
	string _gewicht;
public:
	// ---------- De-/Konstruktoren ----------
	~Schwein() = default;

	Schwein(string name, int alter, string gewicht);
	Schwein(string name, int alter);
	Schwein(string name);
	Schwein();

	// ---------- Getter ----------
	string getGewicht() const { return _gewicht; }
	string toString() const;
	string getLaut() const override;

	// ---------- Setter ----------
	void setGewicht(string value);
};

