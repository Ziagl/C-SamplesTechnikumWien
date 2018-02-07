#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

typedef struct Position
{
	int _x;
	int _y;
}t_position;

enum Race
{
	HUMAN = 0,
	ORC = 1,
	DWARF = 2
};

enum Gender
{
	MALE = 0,
	FEMALE = 1
};

class Character
{
public:
	Character(void);
	Character(int x, int y, int race, int gender);
	~Character(void);
	virtual std::string getString();
protected:
	t_position _position;
	int _race;
	int _gender;
};
#endif