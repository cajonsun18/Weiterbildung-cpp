#include "person.h"
#include <regex>

string Person::toString()
{
	return _nachname + ", " + _vorname + ", " + _strasse + ", "
		+ _plz + ", " + _ort + "\n";
}

void Person::setNachname(string value)
{
	regex muster("([A-ZÄÖÜ][a-zäöüß]*)([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster))
	{
		_nachname = value;
	}
	else
	{
		throw exception("Falsche Eingabe bei dem Nachnamen");
	}
}

void Person::setVorname(string value)
{
	regex muster("[A-ZÄÖÜ][a-zäöüß]*([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster))
	{
		_vorname = value;
	}
	else
	{
		throw exception("Falsche Eingabe bei dem Vornamen");
	}
}

void Person::setStrasse(string value)
{
	regex muster("([A-ZÄÖÜ][a-zäöüß]*)([ ][SWP][a-zäöüß]*)?[ ]([0-9]{1,3})$");
	if (regex_match(value, muster))
	{
		_strasse = value;
	}
	else
	{
		throw exception("Falsche Eingabe bei der Strasse");
	}
}

void Person::setPlz(string value)
{
	regex muster("[1-9][0-9]{4}");
	if (regex_match(value, muster))
	{
		_plz = value;
	}
	else
	{
		throw invalid_argument("Falsche Eingabe bei der Plz");
	}
}

void Person::setOrt(string value)
{
	regex muster("[A-ZÄÖÜ][a-zäöüß]*");
	if (regex_match(value, muster))
	{
		_ort = value;
	}
	else
	{
		throw exception("Falsche Eingabe bei dem Ort");
	}
}
