#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

typedef struct Item
{
	std::string _name;
	int _value;
}t_item;

class Player:public Character
{
public:
	Player(void);
	Player(int x, int y, int race, int gender, std::string itemname, int itemvalue);
	~Player(void);
	void move();
	void jump();
	void die();
	std::string getString();
private:
	Item _item;
	std::string _control;
};
#endif