#include "hund.h"

Hund::Hund(string name, int alter, string rasse)
{
    setName(name);
    setAlter(alter);
    setRasse(rasse);
}

Hund::Hund(string name, int alter)
    : Hund(name, alter, "NV") // :Tier(name, farbe, alter), _rasse("NV")
{
}

Hund::Hund(string name)
    : Hund(name, 1) // :Tier(name, farbe), _rasse("NV")
{
}

Hund::Hund()
    : Hund("NV")
{
}

string Hund::toString() const
{
    return Tier::toString()
        + "Rasse: " + _rasse + "\n";
}

string Hund::getLaut() const
{
    return "Wau Wau";
}

void Hund::setRasse(string value)
{
    _rasse = value;
}
