#include "01_Item.h"

void Item::SetItemInfo(const char* _name, uint _damage, uint _def)
{
	strcpy(name, _name);
	damage = _damage;
	def = _def;
}

void Item::PrintItemInfo() const
{
	cout << "�̸� : " << name << endl;
	cout << "���ݷ� : " << damage << endl;
	cout << "���� : " << def << endl;
}
