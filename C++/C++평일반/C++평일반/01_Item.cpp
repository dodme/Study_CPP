#include "01_Item.h"

void Item::SetItemInfo(const char* _name, uint _damage, uint _def)
{
	strcpy(name, _name);
	damage = _damage;
	def = _def;
}

void Item::PrintItemInfo() const
{
	cout << "이름 : " << name << endl;
	cout << "공격력 : " << damage << endl;
	cout << "방어력 : " << def << endl;
}
