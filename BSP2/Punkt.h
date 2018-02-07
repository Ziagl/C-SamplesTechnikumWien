#pragma once

class Punkt
{
public:
	Punkt(void);
	Punkt(int x, int y);
	~Punkt(void);
	virtual int size();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
protected:
	int _x;
	int _y;
};
