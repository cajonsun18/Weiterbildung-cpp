#include "tier.h"

Tier::Tier(string name, string farbe, int alter)
{
	setName(name);
	setFarbe(farbe);
	setAlter(alter);
}

Tier::Tier(string name, string farbe)
	: Tier(name, farbe, 1)
{}

Tier::Tier(string name)
	: Tier(name, "NV")
{}

Tier::Tier()
	: Tier("NV")
{}

string Tier::toString() const
{
	return "\n" "TIER" "\n"
		"Name: " + _name + "\n"
		+ "Farbe: " + _farbe + "\n"
		+ "Alter: " + to_string(_alter) + "\n";
}

void Tier::setName(string value)
{
	_name = value;
}

void Tier::setFarbe(string value)
{
	_farbe = value;
}

void Tier::setAlter(int value)
{
	_alter = value;
}
