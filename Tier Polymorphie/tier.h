#pragma once
#include <string>
using namespace std;

#ifndef _TIER_H_
#define _TIER_H_

class Tier
{
private:
	string _name;
	int _alter;
public:
	// ---------- De-/Konstruktoren ----------
	~Tier() = default;

	Tier(string name, int alter);
	Tier(string name);
	Tier();

	// ---------- Getter ----------
	string getName() const { return _name; }
	int getAlter() const { return _alter; }
	virtual string toString() const = 0;
	virtual string getLaut() const = 0;

	// ---------- Setter ----------
	void setName(string value);
	void setAlter(int value);
};

#endif