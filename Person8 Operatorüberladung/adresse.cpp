#include "adresse.h"
#include <regex>
#include <stdexcept>

Adresse::Adresse(string adressart, string strasse, string hausnr, string plz, string ort)
{
	setAdressart(adressart);
	setStrasse(strasse);
	setHausNr(hausnr);
	setPlz(plz);
	setOrt(ort);
}

Adresse::Adresse()
	:_adressart("NV"), _strasse("NV"), _hausnr("NV"), _plz("NV)"), _ort("NV")
{
}

string Adresse::toString() const
{
	return "Strasse: " + _strasse + "\n"
		+ "Hausnr: " + _hausnr + "\n"
		+ "Plz: " + _plz + "\n"
		+ "Ort: " + _ort + "\n";
}

void Adresse::setAdressart(string value)
{
	regex muster("^[A-Za-zÄÖÜäöüß][a-zäöüß]*$");

	if (value == "NV" || regex_match(value, muster))
	{
		_adressart = value;
	}
	else
	{
		throw invalid_argument("Fehler bei Adressart: " + value);
	}
}

void Adresse::setStrasse(string value)
{
	regex muster("^[A-Za-zÄÖÜäöüß][a-zäöüß]*$");

	if (value == "NV" || regex_match(value, muster))
	{
		_strasse = value;
	}
	else
	{
		throw invalid_argument("Fehler bei Strasse: " + value);
	}
}

void Adresse::setHausNr(string value)
{
	regex muster("^[1-9][0-9]?[0-9]?[A-Za-z]?$");

	if (value == "NV" || regex_match(value, muster))
	{
		_hausnr = value;
	}
	else
	{
		throw invalid_argument("Fehler bei Hausnummer: " + value);
	}
}

void Adresse::setPlz(string value)
{
	regex muster("^(0[1-9]|[1-9][0-9])[0-9]{3}$");

	if (value == "NV" || regex_match(value, muster))
	{
		_plz = value;
	}
	else
	{
		throw invalid_argument("Fehler bei PLZ: " + value);
	}
}

void Adresse::setOrt(string value)
{
	regex muster("^[A-Za-zÄÖÜäöüß][A-Za-zÄÖÜäöüß .'()/-]{0,58}[A-Za-zÄÖÜäöüß.)]$");

	if (value == "NV" || regex_match(value, muster))
	{
		_ort = value;
	}
	else
	{
		throw invalid_argument("Fehler bei Ort: " + value);
	}
}
