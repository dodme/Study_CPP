#include "Util.h"

int Random(int maxValue)
{
	return rand() % maxValue + 1;
}

void PrintBattleInfo(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster)
{
	cout << "-----------------------------------" << endl;
	cout << "전사 HP : " << warrior->GetHp() << endl;
	cout << "전사의 다음 행동 : ";
	switch (warrior->GetState())
	{
	case 0:
		cout << "공격" << endl;
		break;
	case 1:
		cout << "버서커" << endl;
		break;
	case 2:
		cout << "도발" << endl;
		break;
	case 3:
		cout << "갑옷파괴" << endl;
		break;
	case 4:
		cout << "방어" << endl;
		break;
	case 5:
		cout << "사망" << endl;
		break;
	}
	cout << "마법사 HP : " << mage->GetHp() << endl;
	cout << "마법사의 다음 행동 : ";
	switch (mage->GetState())
	{
	case 0:
		cout << "공격" << endl;
		break;
	case 1:
		cout << "파이어볼" << endl;
		break;
	case 2:
		cout << "파이어월" << endl;
		break;
	case 3:
		cout << "메테오" << endl;
		break;
	case 4:
		cout << "방어" << endl;
		break;
	case 5:
		cout << "사망" << endl;
		break;
	}
	cout << "성기사 HP : " << crusader->GetHp() << endl;
	cout << "성기사의 다음 행동 : ";
	switch (crusader->GetState())
	{
	case 0:
		cout << "공격" << endl;
		break;
	case 1:
		cout << "힐" << endl;
		break;
	case 2:
		cout << "성스러운 보호막" << endl;
		break;
	case 3:
		cout << "전투의 열광" << endl;
		break;
	case 4:
		cout << "방어" << endl;
		break;
	case 5:
		cout << "사망" << endl;
		break;
	}
	cout << "-----------------------------------" << endl;
	cout << "몬스터 HP : " << monster->GetHp() << endl;
	cout << "-----------------------------------" << endl;
}

void Clear()
{
	system("cls");
}

void Delay()
{
	_sleep(3000);
}
