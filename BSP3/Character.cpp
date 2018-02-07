#include "Character.h"

Character::Character(void)
{
}

Character::Character(int x, int y, int race, int gender)
{
	_position._x = x;
	_position._y = y;
	_race = HUMAN;
	_gender = MALE;
}

Character::~Character(void)
{
}

std::string Character::getString()
{
	return "";
}