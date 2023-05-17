#pragma once
#include "Character.h"

class Warrior : public Character
{

public:
	Warrior();
	void PrintWarriorInfo();
	void WarriorBuffDebuff(int burserkerHp, int burserkerDamage, int burserkerDef);
};
