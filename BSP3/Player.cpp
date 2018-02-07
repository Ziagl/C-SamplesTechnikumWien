#include "Player.h"
#include <sstream>
Player::Player(void)
{
}

Player::Player(int x, int y, int race, int gender, std::string itemname, int itemvalue)
{
	_position._x = x;
	_position._y = y;
	_race = race;
	_gender = gender;
	_item._name = itemname;
	_item._value = itemvalue;
}

Player::~Player(void)
{
}

void Player::move()
{
	_control += "move ";
}

void Player::jump()
{
	_control += "jump ";
}

void Player::die()
{
	_control += "die ";
}

std::string Player::getString()
{
	std::ostringstream ostream;

	ostream<<"Player: "<<_position._x<<","<<_position._y<<" | ";
	switch(_gender)
	{

		case MALE: ostream<<"Male | ";break;
		case FEMALE: ostream<<"Female | ";break;
	}
	switch(_race)
	{
		case HUMAN: ostream<<"Human | ";break;
		case ORC: ostream<<"Orc | ";break;
		case DWARF: ostream<<"Dwarf | ";break;
	}
	ostream<<_item._name<<": "<<_item._value;
	ostream<<" "<<_control;

	return ostream.str();
}