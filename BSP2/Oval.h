#pragma once			//damit dieser Header nur einmal eingebunden wird! sonst Compilerfehler Typneudefinition...
						//besser: #ifndef PUNKT_H
						// #define PUNKT_H
						// .. #endif
#include "Punkt.h"

class Oval:public Punkt
{
public:
	Oval(void);
	Oval(int x, int y, int radius);
	~Oval(void);
	virtual int size();
protected:
	int _radius;
};
