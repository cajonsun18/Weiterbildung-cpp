#include "tier.h"

Tier::Tier(string name, int alter)
{
	setName(name);
	setAlter(alter);
}

Tier::Tier(string name)
	: Tier(name, 0)
{
}

Tier::Tier()
	: Tier("NV")
{
}

string Tier::toString() const
{
	return "\n" "TIER" "\n"
		"Name: " + _name + "\n"
		+ "Alter: " + to_string(_alter) + "\n";
}

void Tier::setName(string value)
{
	_name = value;
}

void Tier::setAlter(int value)
{
	_alter = value;
}
