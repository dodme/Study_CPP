#pragma once
#include "GameObject.h"
#include "Monster.h"


enum Job
{
	Warrior,
	Archer,
};

class Character : public GameObject
{
private:
	Job job;
	char name[80];
public:
	Character(const char* name, Job job);
	void Battle(Monster* monster);
};


