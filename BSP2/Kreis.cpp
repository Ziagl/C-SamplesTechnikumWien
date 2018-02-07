#include "Kreis.h"

Kreis::Kreis(void)
{
}

Kreis::Kreis(int x, int y, int radius)
{
	setX(x);
	setY(y);
	_radius=radius;
}

Kreis::~Kreis(void)
{
}

int Kreis::size()
{
	return _radius*_radius*3.1415;
}
