#include "Punkt.h"

Punkt::Punkt(void)
{
}

Punkt::Punkt(int x, int y)
{
	_x=x;
	_y=y;
}

Punkt::~Punkt(void)
{
}

int Punkt::getX()
{
	return _x;
}

int Punkt::getY()
{
	return _y;
}

void Punkt::setX(int x)
{
	_x=x;
}

void Punkt::setY(int y)
{
	_y=y;
}

int Punkt::size()
{
	return 0;
}