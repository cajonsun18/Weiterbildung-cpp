#pragma once
#include <iostream>

#ifndef _MYLIB_H_ // Heißt: If not defined
#define _MYLIB_H_

void init();
int random(int min, int max);
double random(double min, double max);
int getIntZahl(std::string msg, int min, int max);
double getDblZahl(std::string msg, double min, double max);

#endif