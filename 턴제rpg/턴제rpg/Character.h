#pragma once
#include "Monster.h"

enum State
{
	NormalAttack = 0,
	Skill1,
	Skill2,
	Skill3,
	Meditation,
	Die,
};

class Character
{
protected:
	int maxHp;
	int hp;
	int maxMp;
	int mp;
	int damage;
	int def;
	State state;

public:
	void SetStat(int hp, int mp, int damage, int def);
	void AttackByMonster(int monsterDamage);
	int GetHp();
	int GetMp();
	int GetDamage(int buffTurn);
	int GetDef();
	int GetState();
	void HealHp(int hp);
	void PlusMinusMp(int mp);
	void PrintCharacterInfo();
	void SetState(State state);
};
