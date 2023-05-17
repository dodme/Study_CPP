#include "Character.h"

void Character::SetStat(int hp, int mp, int damage, int def)
{
	maxHp = hp;
	this->hp = hp;
	maxMp = mp;
	this->mp = mp;
	this->damage = damage;
	this->def = def;
}

void Character::AttackByMonster(int monsterDamage)
{
	this->hp -= monsterDamage - def;
}

int Character::GetHp()
{
	return hp;
}

int Character::GetDamage(int buffTurn)
{
	return (buffTurn > 0) ? damage * 1.5f : damage;
}

int Character::GetDef()
{
	return def;
}

void Character::PrintCharacterInfo()
{
	cout << "Hp : " << hp << "/" << maxHp << endl;
	cout << "Mp : " << mp << "/" << maxMp << endl;
	cout << "공격력 : " << damage << endl;
	cout << "방어력 : " << def << endl;
}

void Character::SetState(State state)
{
	this->state = state;
}

int Character::GetState()
{
	return state;
}

void Character::HealHp(int hp)
{
	if ((this->hp + hp) < maxHp)
		this->hp += hp;
	else if ((this->hp + hp) >= maxHp)
		this->hp = maxHp;
}

void Character::PlusMinusMp(int mp)
{
	if ((this->mp + mp) < maxMp)
		this->mp += mp;
	else if ((this->mp + mp) >= maxMp)
		this->mp = maxMp;
}

int Character::GetMp()
{
	return mp;
}
