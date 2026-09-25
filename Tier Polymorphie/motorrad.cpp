#include "motorrad.h"

Motorrad::Motorrad(string kennzeichen, int reifenAnzahl)
    :Fahrzeug(kennzeichen), _reifenAnzahl(reifenAnzahl)
{
}

Motorrad::Motorrad(string kennzeichen)
    :Fahrzeug(kennzeichen), _reifenAnzahl(0)
{
}

Motorrad::Motorrad()
    :Fahrzeug(), _reifenAnzahl(0)
{
}

string Motorrad::toString() const
{
    return Fahrzeug::toString() +
        "Reifenanzahl: " + to_string(_reifenAnzahl);
}

void Motorrad::setReifenanzahl(int value)
{
    _reifenAnzahl = value;
}
