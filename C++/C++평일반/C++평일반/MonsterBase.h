#pragma once
#include "BaseController.h"
#include "CharacterBase.h"

class CharacterBase;

class MonsterBase : public BaseController
{
public:
	virtual void Attack(CharacterBase* character);
	virtual void CounterAttack(CharacterBase* character);
	virtual void Deviate();
};