#include "person.h"
#include <regex>

string Person::toString()
{
	return _nachname + ", " + _vorname + ", " + _strasse + ", " 
		+ _plz + ", " + _ort + "\n";
}

bool Person::setNachname(string value)
{
	regex muster("([A-ZÄÖÜ][a-zäöüß]*)([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster)) 
	{
		_nachname = value;
		return true;
	}
	
	return false;
}

bool Person::setVorname(string value)
{
	regex muster("[A-ZÄÖÜ][a-zäöüß]*([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster))
	{
		_vorname = value;
		return true;
	}

	return false;
}

bool Person::setStrasse(string value)
{
	regex muster("([A-ZÄÖÜ][a-zäöüß]*)([ ][SWP][a-zäöüß]*)?[ ]([0-9]{1,3})$");
	if (regex_match(value, muster))
	{
		_strasse = value;
		return true;
	}

	return false;
}

bool Person::setPlz(string value)
{
	regex muster("[1-9][0-9]{4}");
	if (regex_match(value, muster))
	{
		_plz = value;
		return true;
	}

	return false;
}

bool Person::setOrt(string value)
{
	regex muster("[A-ZÄÖÜ][a-zäöüß]*");
	if (regex_match(value, muster))
	{
		_ort = value;
		return true;
	}

	return false;
}
