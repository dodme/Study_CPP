#pragma once
#include <iostream>
#include "Util.h"

struct Stat
{
public:
	int hp;
	int damage;
	int def;
	int cri;
	int eva;
};

class GameObject
{
protected:
	Stat stat;

public:
	void SetStat(int hp, int damage, int def, int cri, int eva);
};
