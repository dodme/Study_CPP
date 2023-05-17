#pragma once
#include "BaseController.h"
#include "MonsterBase.h"

class MonsterBase;

class CharacterBase : public BaseController
{
public:
	void Movement();
	void AttackOrEscape(MonsterBase* monster);
};
