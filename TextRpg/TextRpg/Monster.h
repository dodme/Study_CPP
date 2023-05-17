#pragma once
#include "GameObject.h"

enum Job
{
	Slime,
	Goblin,
	Troll,
	Golem,
	Dragon,
};

class Monster : public GameObject
{
private:
	char name[80];
	Job job;
public:
	Monster(Job job);
};
