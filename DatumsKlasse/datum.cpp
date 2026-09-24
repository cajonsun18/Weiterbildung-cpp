#include "datum.h"
#include <regex>
#include <stdexcept>

Datum::Datum()
	: Datum("NV", "NV", "NV")
{
}

Datum::Datum(string tag, string monat, string jahr)
{
	setTag(tag);
	setMonat(monat);
	setJahr(jahr);
}

string Datum::toString() const
{
	return "\n" "DATUM" "\n"
		"Tag: " + _tag + "\n"
		+ "Monat: " + _monat + "\n"
		+ "Jahr: " + _jahr + "\n\n";
}

void Datum::setTag(string tag)
{
	regex muster("^[1-9]{2}");
	if (tag == "NV" || regex_match(tag, muster))
	{
		_tag = tag;
	}
	else
	{
		throw invalid_argument("Fehler bei Tag: " + tag);
	}
}

void Datum::setMonat(string monat)
{
	regex muster("^[1-9]{2}");
	if (monat == "NV" || regex_match(monat, muster))
	{
		_monat = monat;
	}
	else
	{
		throw invalid_argument("Fehler bei Monat: " + monat);
	}
}

void Datum::setJahr(string jahr)
{
	regex muster("^[1-9]{4}");
	if (jahr == "NV" || regex_match(jahr, muster))
	{
		_jahr = jahr;
	}
	else
	{
		throw invalid_argument("Fehler bei Jahr: " + jahr);
	}
}
