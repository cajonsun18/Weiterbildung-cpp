#include "schwein.h"

Schwein::Schwein(string name, int alter, string gewicht)
{
    setName(name);
    setAlter(alter);
    setGewicht(gewicht);
}

Schwein::Schwein(string name, int alter)
    : Schwein(name, alter, "NV") // :Tier(name, farbe, alter), _rasse("NV")
{
}

Schwein::Schwein(string name)
    : Schwein(name, 1) // :Tier(name, farbe), _rasse("NV")
{
}

Schwein::Schwein()
    : Schwein("NV")
{
}

string Schwein::toString() const
{
    return Tier::toString()
        + "Gewicht: " + _gewicht + "\n";
}

string Schwein::getLaut() const
{
    return "Oink Oink";
}

void Schwein::setGewicht(string value)
{
    _gewicht = value;
}

