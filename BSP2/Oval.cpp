#include "Oval.h"

Oval::Oval(void)
{
}

Oval::Oval(int x, int y, int radius)
{
	_x=x;
	_y=y;
	_radius=radius;
}

Oval::~Oval(void)
{
}

int Oval::size()
{
	return 1;
}
