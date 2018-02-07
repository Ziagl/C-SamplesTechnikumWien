#include "Rechteck.h"

Rechteck::Rechteck(void)
{
}

Rechteck::Rechteck(int x, int y, int width, int height)
{
	_x=x;
	_y=y;
	_width=width;
	_height=height;
}

Rechteck::~Rechteck()
{
}

int Rechteck::size()
{
	return _width*_height;
}