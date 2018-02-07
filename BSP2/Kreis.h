#include "Oval.h"

class Kreis:public Oval
{
public:
	Kreis(void);
	Kreis(int x, int y, int radius);
	~Kreis(void);
	int size();
};
