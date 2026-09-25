#pragma once
#include "tier.h"
#include <string>
using namespace std;

#ifndef _HUND_H_
#define _HUND_H_

class Kuh :public Tier
{
private:
	string _futter;
public:
	// ---------- Getter ----------
	string getFutterart() const override;

	// ---------- Setter ----------
	void setFutterart(string value) override;
};

#endif