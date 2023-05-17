#include "MonsterBase.h"

void MonsterBase::Attack(CharacterBase* character)
{
	cout << "���Ͱ� �����մϴ�!" << endl;
	character->SetHp(character->GetHp() - stat.damage);
	cout << "���� ����� ü���� " << character->GetHp() << "�Դϴ�." << endl;

}

void MonsterBase::CounterAttack(CharacterBase* character)
{
	int randNumber = rand() % 100 + 1;

	(randNumber >= 50) ? Attack(character) : Deviate();
}

void MonsterBase::Deviate()
{
	cout << "������ ������ ���������ϴ�." << endl;
}
