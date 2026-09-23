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

void Konto::setNachname(string value)
{
	regex muster("([A-ZÄÖÜ][a-zäöüß]*)([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster))
	{
		_nachname = value;
	}
	else
	{
		throw invalid_argument("Falsche Eingabe bei dem Nachnamen");
	}
}

void Konto::setVorname(string value)
{
	regex muster("[A-ZÄÖÜ][a-zäöüß]*([ |-][A-ZÄÖÜ][a-zäöüß]*)?");
	if (regex_match(value, muster))
	{
		_vorname = value;
	}
	else
	{
		throw invalid_argument("Falsche Eingabe bei dem Vornamen");
	}
}

void Konto::setKontonummer(long long value)
{
	// Kontonummer muss genau 10 Ziffern haben
	if ((value / 1'000'000'000) > 0 && (value / 1'000'000'000) < 10)
	{
		_kontonummer = value;
	}
	else
	{
		throw invalid_argument("Falsche Eingabe bei der Kontonummer");
	}

}

void Konto::setKontoart(Kontoart value)
{
	_kontoart = value;
}

void Konto::setKontostand(double value)
{
	double neuKontostand = _kontostand + value;
	if (neuKontostand > -_dispo)
	{
		_kontostand += value;
	}
	else
	{
		throw exception("Du kannst nicht ueber dein Dispo gehen.");
	}
}

string Konto::kontoartToString(Kontoart kontoart)
{
	switch (kontoart) {
	case Kontoart::Girokonto: return "Girokonto";
		break;
	case Kontoart::Sparkonto: return "Sparkonto";
		break;
	default: return "Unbekannt";
	}
}

void Konto::setDispolimit(double value)
{
	if (value > 0) 
	{
		_dispo = value;
	}
	else
	{
		throw out_of_range("Das Dispolimit mit ein positiver Wert sein");
	}
}

void Konto::AddMoney(double value)
{
	setKontostand(value);
}

void Konto::WithdrawMoney(double value)
{
	setKontostand(-value);
}
