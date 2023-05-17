#include "Battle.h"

void Battle(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster)
{
#pragma region 변수
	int turn = 1;
	int burserkerTurn = 0;
	int tauntTurn = 0;
	int armorBreakTurn = 0;
	int barrierBuff = 0;
	int damageUpTurn = 0;
	int choice = 1;
	int monsterChoice = 0;
#pragma endregion

#pragma region 몬스터선택
	cout << "원하시는 몬스터를 선택하세요." << endl;
	cout << "1.드래곤" << endl;
	cin >> monsterChoice;

	switch (monsterChoice)
	{
	case 1:
		monster->SetStat(10000, 500, 50);
		break;
	default:
		cout << "잘못된 입력입니다." << endl;
		break;
	}

	cout << "몬스터와의 전투!" << endl;

#pragma endregion

	while (1)
	{
#pragma region 행동선택

		if (warrior->GetHp() > 0)
			warrior->SetState(NormalAttack);
		if (mage->GetHp() > 0)
			mage->SetState(NormalAttack);
		if (crusader->GetHp() > 0)
			crusader->SetState(NormalAttack);

		while (choice != 0)
		{
			cout << "현재 턴 : " << turn << endl;




			PrintBattleInfo(warrior, mage, crusader, monster);

			cout << endl;
			cout << endl;
			cout << "1. 전사의 행동 선택" << endl;
			cout << "2. 마법사의 행동 선택" << endl;
			cout << "3. 성기사의 행동 선택" << endl;
			cout << "4. 능력치 보기" << endl;
			cout << "0. 선택완료" << endl;

			cin >> choice;
			switch (choice)
			{
			case 1:
				Clear();
				if (warrior->GetState() != 5)
				{
					cout << "-------전사의 행동 선택-------" << endl;
					cout << "1. 기본공격" << endl;
					cout << "2. 버서커" << endl;
					cout << "3. 도발" << endl;
					cout << "4. 갑옷파괴" << endl;
					cout << "5. 명상" << endl;
					int warriorChoice = 0;
					cin >> warriorChoice;
					switch (warriorChoice)
					{
					case 1:
						warrior->SetState(State::NormalAttack);
						break;

					case 2:
						if (warrior->GetHp() >= 500)
							warrior->SetState(State::Skill1);
						else
							cout << "Hp가 부족합니다." << endl;
						break;

					case 3:
						if (warrior->GetMp() >= 50)
							warrior->SetState(State::Skill2);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 4:
						if (warrior->GetMp() >= 100)
							warrior->SetState(State::Skill3);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 5:
						warrior->SetState(State::Meditation);
						break;

					default:
						cout << "잘못된 입력입니다." << endl;
						break;
					}
				}
				else if (warrior->GetState() == 5)
				{
					cout << "사망상태입니다." << endl;
				}
				break;
			case 2:
				Clear();
				if (mage->GetState() != 5)
				{
					cout << "-------마법사의 행동 선택-------" << endl;
					cout << "1. 기본공격" << endl;
					cout << "2. 파이어볼" << endl;
					cout << "3. 파이어레인" << endl;
					cout << "4. 메테오" << endl;
					cout << "5. 명상" << endl;
					int mageChoice = 0;
					cin >> mageChoice;
					switch (mageChoice)
					{
					case 1:
						mage->SetState(State::NormalAttack);
						break;

					case 2:
						if (mage->GetMp() >= 70)
							mage->SetState(State::Skill1);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 3:
						if (mage->GetMp() >= 100)
							mage->SetState(State::Skill2);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 4:
						if (mage->GetMp() >= 150)
							mage->SetState(State::Skill3);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 5:
						mage->SetState(State::Meditation);
						break;

					default:
						cout << "잘못된 입력입니다." << endl;
						break;
					}
				}
				else if (mage->GetState() == 5)
				{
					cout << "사망상태입니다." << endl;
				}
				break;
			case 3:
				Clear();
				if (crusader->GetState() != 5)
				{
					cout << "-------성기사의 행동 선택-------" << endl;
					cout << "1. 기본공격" << endl;
					cout << "2. 힐" << endl;
					cout << "3. 성스러운 보호막" << endl;
					cout << "4. 전투의 열광" << endl;
					cout << "5. 명상" << endl;
					int crusaderChoice = 0;
					cin >> crusaderChoice;
					switch (crusaderChoice)
					{
					case 1:
						crusader->SetState(State::NormalAttack);
						break;

					case 2:
						if (crusader->GetMp() >= 80)
							crusader->SetState(State::Skill1);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 3:
						if (crusader->GetMp() >= 200)
							crusader->SetState(State::Skill2);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 4:
						if (crusader->GetMp() >= 100)
							crusader->SetState(State::Skill3);
						else
							cout << "Mp가 부족합니다." << endl;
						break;

					case 5:
						crusader->SetState(State::Meditation);
						break;

					default:
						cout << "잘못된 입력입니다." << endl;
						Delay();
						break;
					}
				}
				else if (crusader->GetState() == 5)
				{
					cout << "사망상태입니다." << endl;
					Delay();
				}
				break;
			case 4:
			{

				Clear();
				int lookStat = 0;
				cout << "어떤 캐릭터의 스텟을 보시겠습니까?" << endl;
				cout << "1. 전사   2. 마법사   3. 성기사" << endl;
				cin >> lookStat;
				switch (lookStat)
				{
				case 1:
					warrior->PrintWarriorInfo();
					break;

				case 2:
					mage->PrintMageInfo();
					break;

				case 3:
					crusader->PrintCrusaderInfo();
					break;

				default:
					cout << "잘못된 입력입니다." << endl;
					break;
				}
				break;
			}
			case 0:
				break;
			default:
				cout << "잘못된 입력입니다." << endl;
				break;
			}
			Delay();
			Clear();
		}
		choice = 1;
#pragma endregion


		BuffEnd(warrior, crusader, monster, burserkerTurn, tauntTurn, armorBreakTurn, barrierBuff, damageUpTurn, turn);
		PrintBattleInfo(warrior, mage, crusader, monster);

#pragma region 전투
		switch (warrior->GetState())
		{
		case 0:
			cout << "전사의 공격!" << endl;
			cout << (warrior->GetDamage(damageUpTurn) - monster->GetDef()) << "의 데미지를 입혔다." << endl;
			monster->AttackByPlayer(warrior->GetDamage(damageUpTurn));
			break;

		case 1:
			cout << "버서커스킬 사용!" << endl;
			if (burserkerTurn == 0)
				warrior->WarriorBuffDebuff(-500, 200, -50);
			else if (burserkerTurn > 0)
				warrior->WarriorBuffDebuff(-500, 0, 0);
			burserkerTurn = turn + 3;
			break;

		case 2:
			cout << "도발스킬 사용!" << endl;
			warrior->PlusMinusMp(-50);
			if (tauntTurn == 0)
				warrior->WarriorBuffDebuff(0, 0, 50);
			tauntTurn = turn + 3;
			break;

		case 3:
			cout << "갑옷파괴 공격!" << endl;
			warrior->PlusMinusMp(-100);
			if (armorBreakTurn == 0)
				monster->MonsterBuffDebuff(0, 0, -50);
			armorBreakTurn = turn + 3;
			cout << (warrior->GetDamage(damageUpTurn) * 1.2f - monster->GetDef()) << "의 데미지를 입혔다." << endl;
			monster->AttackByPlayer(warrior->GetDamage(damageUpTurn) * 1.2f);
			break;

		case 4:
			cout << "명상" << endl;
			cout << "100의 Mp를 회복했습니다." << endl;
			warrior->PlusMinusMp(100);
			break;

		case 5:
			cout << "전사는 사망상태입니다." << endl;
			break;

		default:
			break;
		}

		switch (mage->GetState())
		{
		case 0:
			cout << "마법사의 공격!" << endl;
			cout << (mage->GetDamage(damageUpTurn) - monster->GetDef()) << "의 데미지를 입혔다." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn));
			break;

		case 1:
			cout << "파이어볼 발동!" << endl;
			mage->PlusMinusMp(-70);
			cout << (mage->GetDamage(damageUpTurn) * 1.5f - monster->GetDef()) << "의 데미지를 입혔다." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn) * 1.5f);
			break;

		case 2:
			cout << "파이어레인 발동!" << endl;
			mage->PlusMinusMp(-100);
			cout << (mage->GetDamage(damageUpTurn) * 2 - monster->GetDef()) << "의 데미지를 입혔다." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn) * 2);
			break;

		case 3:
			cout << "메테오 발동!" << endl;
			mage->PlusMinusMp(-200);
			cout << (mage->GetDamage(damageUpTurn) * 3 - monster->GetDef()) << "의 데미지를 입혔다." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn) * 3);
			break;

		case 4:
			cout << "명상" << endl;
			cout << "100의 Mp를 회복했습니다." << endl;
			mage->PlusMinusMp(100);
			break;

		case 5:
			cout << "마법사는 사망상태입니다." << endl;
			break;

		default:
			break;
		}

		switch (crusader->GetState())
		{
		case 0:
			cout << "성기사의 공격!" << endl;
			cout << (crusader->GetDamage(damageUpTurn) - monster->GetDef()) << "의 데미지를 입혔다." << endl;
			monster->AttackByPlayer(crusader->GetDamage(damageUpTurn));
			break;

		case 1:
			cout << "힐 발동!" << endl;
			crusader->PlusMinusMp(-80);
			cout << "아군 전체는 " << crusader->GetDamage(damageUpTurn) * 2 << "의 체력을 회복했다." << endl;
			warrior->HealHp(crusader->GetDamage(damageUpTurn) * 2);
			mage->HealHp(crusader->GetDamage(damageUpTurn) * 2);
			crusader->HealHp(crusader->GetDamage(damageUpTurn) * 2);
			break;

		case 2:
			cout << "성스러운 보호막 발동!" << endl;
			crusader->PlusMinusMp(-200);
			barrierBuff = 1;
			break;

		case 3:
			cout << "전투의 열광 발동!" << endl;
			crusader->PlusMinusMp(-100);
			damageUpTurn = turn + 3;
			break;

		case 4:
			cout << "명상" << endl;
			cout << "100의 Mp를 회복했습니다." << endl;
			crusader->PlusMinusMp(100);
			break;

		case 5:
			cout << "성기사는 사망상태입니다." << endl;
			break;

		default:
			break;
		}

		cout << endl;
		cout << endl;
		cout << endl;

		switch (monsterChoice)
		{
		case 1:
			if (monster->GetHp() > 0)
				DragonPattern(warrior, mage, crusader, monster, tauntTurn, &barrierBuff, turn);
			break;

		default:
			break;
		}

		if ((warrior->GetHp() <= 0) && (mage->GetHp() <= 0) && (crusader->GetHp() <= 0))
		{
			cout << "전투에 패배했습니다." << endl;
			Delay();
			Clear();
			break;
		}
		else if (monster->GetHp() <= 0)
		{
			cout << "전투에 승리했습니다." << endl;
			Delay();
			Clear();
			break;
		}

		turn++;
		burserkerTurn--;
		tauntTurn--;
		armorBreakTurn--;
		barrierBuff = 0;
		damageUpTurn--;
#pragma endregion


	}
}

void BuffEnd(Warrior* warrior, Crusader* crusader, Monster* monster, int burserkerTurn, int tauntTurn, int armorBreakTurn, int barrierBuff, int damageUpTurn, int turn)
{
	if (burserkerTurn == turn)
	{
		warrior->WarriorBuffDebuff(0, -200, 50);
	}
	if (tauntTurn == turn)
	{
		warrior->WarriorBuffDebuff(0, 0, -50);
	}
	if (armorBreakTurn == turn)
	{
		monster->MonsterBuffDebuff(0, 0, 50);
	}
}
