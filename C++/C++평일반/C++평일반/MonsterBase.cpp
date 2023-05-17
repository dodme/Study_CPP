#include "MonsterBase.h"

void MonsterBase::Attack(CharacterBase* character)
{
	cout << "몬스터가 공격합니다!" << endl;
	character->SetHp(character->GetHp() - stat.damage);
	cout << "현재 당신의 체력은 " << character->GetHp() << "입니다." << endl;

}

void MonsterBase::CounterAttack(CharacterBase* character)
{
	int randNumber = rand() % 100 + 1;

	(randNumber >= 50) ? Attack(character) : Deviate();
}

void MonsterBase::Deviate()
{
	cout << "몬스터의 공격이 빗나갔습니다." << endl;
}
