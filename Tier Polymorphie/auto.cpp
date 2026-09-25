#include "auto.h"

Auto::Auto(string kennzeichen, string dachtyp)
    :Fahrzeug(kennzeichen), _dachTyp(dachtyp)
{
}

Auto::Auto(string kennzeichen)
    :Fahrzeug(kennzeichen), _dachTyp(0)
{
}

Auto::Auto()
    :Fahrzeug(), _dachTyp(0)
{
}

string Auto::toString() const
{
    return Fahrzeug::toString() +
        "Dachtyp: " + _dachTyp;
}

void Auto::setDachTyp(string value)
{
    _dachTyp = value;
}

