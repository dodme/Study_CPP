#include "Monster.h"

void Monster::SetStat(int hp, int damage, int def)
{
	this->hp = hp;
	this->damage = damage;
	this->def = def;
}

int Monster::GetHp()
{
	return hp;
}

int Monster::GetDamage()
{
	return damage;
}

int Monster::GetDef()
{
	return def;
}

void Monster::AttackByPlayer(int damage)
{
	hp -= (damage - def);
}

void Monster::MonsterBuffDebuff(int hp, int damage, int def)
{
	this->hp -= hp;
	this->damage -= damage;
	this->def -= def;
}
