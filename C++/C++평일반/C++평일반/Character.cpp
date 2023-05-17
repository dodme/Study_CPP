#include "Character.h"

Character::Character(const char* _name, uint _damage, uint _def)
{
	strcpy(name, _name);
	damage = _damage;
	def = _def;
}

void Character::PrintCharacterInfo() const
{
	cout << "당신의 이름은 : " << name << endl;
	cout << "당신의 공격력은 : " << damage << endl;
	cout << "당신의 방어력은 : " << def << endl;
}

void Character::AddDamage(uint _damage)
{
	damage += _damage;
}

void Character::AddDef(uint _def)
{
	def += _def;
}
