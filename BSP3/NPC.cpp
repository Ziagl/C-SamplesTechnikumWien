#include "NPC.h"
#include <sstream>

NPC::NPC(void)
{
}

NPC::NPC(int x, int y, int race, int gender, int task)
{
	_position._x = x;
	_position._y = y;
	_race = race;
	_gender = gender;
	_task = task;
}

NPC::~NPC(void)
{
}

std::string NPC::getString()
{
	std::ostringstream ostream;

	ostream<<"NPC: "<<_position._x<<","<<_position._y<<" | ";
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
	switch(_task)
	{
		case WAIT: ostream<<"waiting";break;
		case FIGHT: ostream<<"fighting";break;
		case WORK: ostream<<"working";break;
		case SEARCH: ostream<<"searching";break;
	}

	return ostream.str();
}