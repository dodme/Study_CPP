#pragma once
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

typedef unsigned int uint;

class Character
{
private:
	char name[256];
	uint damage;
	uint def;

public:
	Character(const char* _name, uint _damage, uint _def);
	void PrintCharacterInfo() const;
	// �����۸�ŭ �ɷ�ġ �߰��� �� ����� �Լ�
	void AddDamage(uint _damage);
	void AddDef(uint _def);
};