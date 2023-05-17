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
	// 아이템만큼 능력치 추가할 때 사용할 함수
	void AddDamage(uint _damage);
	void AddDef(uint _def);
};