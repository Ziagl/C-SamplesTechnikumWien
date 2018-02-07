#ifndef _NPC_H_
#define _NPC_H_

#include "Character.h"

enum Task
{
	WAIT = 0,
	FIGHT = 1,
	WORK = 2,
	SEARCH = 3
};

class NPC:public Character
{
public:
	NPC(void);
	NPC(int x, int y, int race, int gender, int task);
	~NPC(void);
	std::string getString();
private:
	int _task;
};
#endif