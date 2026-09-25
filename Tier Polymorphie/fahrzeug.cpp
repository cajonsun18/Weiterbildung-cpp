#include "fahrzeug.h"

Fahrzeug::Fahrzeug(string kennzeichen)
{
    setKennzeichen(kennzeichen);
}

Fahrzeug::Fahrzeug()
	:Fahrzeug("NV")
{
}

string Fahrzeug::toString() const
{
	return "\n" "FAHRZEUG" "\n"
		"Kennzeichen: " + _kennzeichen + "\n";
}

void Fahrzeug::setKennzeichen(string value)
{
	_kennzeichen = value;
}
