#pragma once
#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

class Monster
{
private:
	int hp;
	int damage;
	int def;

public:
	void SetStat(int hp, int damage, int def);
	int GetHp();
	int GetDamage();
	int GetDef();
	void AttackByPlayer(int damage);
	void MonsterBuffDebuff(int hp, int damage, int def);
};
