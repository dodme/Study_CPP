#include "Character.h"

Character::Character(const char* _name, uint _damage, uint _def)
{
	strcpy(name, _name);
	damage = _damage;
	def = _def;
}

void Character::PrintCharacterInfo() const
{
	cout << "����� �̸��� : " << name << endl;
	cout << "����� ���ݷ��� : " << damage << endl;
	cout << "����� ������ : " << def << endl;
}

void Character::AddDamage(uint _damage)
{
	damage += _damage;
}

void Character::AddDef(uint _def)
{
	def += _def;
}
