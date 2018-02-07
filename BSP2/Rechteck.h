#pragma once

#include "Punkt.h"

class Rechteck:public Punkt
{
public:
	Rechteck();
	Rechteck(int x, int y, int width, int height);
	~Rechteck();
	virtual int size();
protected:
	int _width;
	int _height;
};