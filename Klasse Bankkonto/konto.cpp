#include "konto.h"
#include <regex>
#include <iostream>

string Konto::toString()
{
	return "\n" "KONTODATEN" "\n"
		  "Nachname: " + _nachname + "\n" 
		+ "Vorname: " + _vorname + "\n" 
		+ "Kontoart: " + kontoartToString(_kontoart) + "\n"
		+ "Kontonummer: " + to_string(_kontonummer) + "\n"
		+ "Kontostand: " + to_string(_kontostand) + "\n" 
		+ "Dispo: " + to_string(_dispo) + "\n\n";
}

bool Konto::setNachname(string value)
{
	regex muster("([A-ZÄÖÜ][a-zäöüß]*)([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster))
	{
		_nachname = value;
		return true;
	}

	return false;
}

bool Konto::setVorname(string value)
{
	regex muster("[A-ZÄÖÜ][a-zäöüß]*([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster))
	{
		_vorname = value;
		return true;
	}

	return false;
}

bool Konto::setKontonummer(long long value)
{
	// Kontonummer muss genau 10 Ziffern haben
	if ((value / 1'000'000'000) > 0 && (value / 1'000'000'000) < 10)
	{
		_kontonummer = value;
		return true;
	}

	return false;
	
}

bool Konto::setKontoart(Kontoart value)
{
	_kontoart = value;
    return true;
}

bool Konto::setKontostand(double value)
{
	double neuKontostand = _kontostand + value;
	if (neuKontostand > -_dispo) 
	{
		_kontostand += value;
		return true;
	}
	else
	{
		return false;
	}
    
	return false;
}

string Konto::kontoartToString(Kontoart kontoart)
{
	switch (kontoart) {
	case Kontoart::Girokonto : return "Girokonto";
		break;
	case Kontoart::Sparkonto : return "Sparkonto";
		break;
	default					 : return "Unbekannt";
	}
}

bool Konto::setDispolimit(double value)
{
	_dispo = value;
    return false;
}

bool Konto::AddMoney(double value)
{
	return setKontostand(value);
}

bool Konto::WithdrawMoney(double value)
{
	return setKontostand(-value);
}
