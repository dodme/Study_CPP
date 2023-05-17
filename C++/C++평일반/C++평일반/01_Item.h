#pragma once
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

typedef unsigned int uint;

class Item
{
private:
	char name[256];
	uint damage;
	uint def;
public:
	void SetItemInfo(const char* _name, uint _damage, uint _def);
	void PrintItemInfo() const;
	uint GetDamage() { return damage; }
	uint GetDef() { return def; }
};
