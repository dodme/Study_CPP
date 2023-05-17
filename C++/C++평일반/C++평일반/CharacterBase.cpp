#include "CharacterBase.h"

void CharacterBase::Movement()
{
	int inputNumber = 0;
	cout << "어디로 이동하시겠습니까?" << endl;
	cout << "1. 왼쪽 2. 오른쪽 3. 점프" << endl;
	cin >> inputNumber;

	switch (inputNumber)
	{
	case 1:
		cout << "왼쪽으로 움직입니다." << endl;
		vector.x -= stat.moveSpeed;
		break;
	case 2:
		cout << "오른쪽으로 움직입니다." << endl;
		vector.x += stat.moveSpeed;
		break;
	case 3:
		cout << "점프합니다." << endl;
		for (int i = 0; i < stat.jumpSpeed; i++)
		{
			vector.y += 1;
			vector.PrintVector();
			_sleep(500);
		}
		for (int i = 0; i < stat.jumpSpeed; i++)
		{
			vector.y -= 1;
			vector.PrintVector();
			_sleep(500);
		}
		system("cls");
		break;
	default:
		break;
	}
}

void CharacterBase::AttackOrEscape(MonsterBase* monster)
{
	GetTickCount64();
	cout << "어떤 행동을 하시겠습니다?" << endl;
	cout << "1. 이동 2. 공격 3. 도망" << endl;
	int inputNumber = 0;
	cin >> inputNumber;
	
	switch (inputNumber)
	{
		GetTickCount64();
	case 1:
		Movement();
		// TODO
		/// 몬스터가 캐릭터 공격시 데미지 처리

		// Movement()에서 점프처리가 끝났는데 함수 밖에서 어떻게 점프했다고 받아와서
		// 공격을 회피해야할지 모르겠어요ㅠ

		cout << "몬스터가 공격합니다!" << endl;
		SetHp(GetHp() - monster->GetStat().damage);
		cout << "당신이" << monster->GetStat().damage << "만큼의 피해를 입었습니다." << endl;
		cout << "당신의 현재 체력은 " << stat.hp << "입니다." << endl;

		return;
	case 2:
		cout << "당신이 몬스터를 때립니다!" << endl;
		monster->SetHp(monster->GetHp() - stat.damage);
		cout << "몬스터에게 " << stat.damage << "만큼 피해를 입힙니다." << endl;
		cout << "현재 몬스터의 체력은 " << monster->GetHp() << "입니다." << endl;

		// TODO 
		/// 몬스터의 확률반격
		if ((rand() % 100 + 1) > 50)
		{
			cout << "몬스터가 반격합니다!" << endl;
			SetHp(GetHp() - monster->GetStat().damage);
			cout << "몬스터에게" << monster->GetStat().damage << "만큼 피해를 입었습니다." << endl;
			cout << "당신의 현재 체력은 " << stat.hp << "입니다." << endl;
		}


		break;
	case 3:
		cout << "쫄보쉨" << endl;
		return;
	default:
		cout << "너의 코드는.." << endl;
		return;
	}

	// TODO
	/// 몬스터의 hp가 0이하일경우 MonsterBase 안에 Die()호출
	if ((monster->GetHp()) <= 0)
	{
		monster->MonsterDie();
	}

}
