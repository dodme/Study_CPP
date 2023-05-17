#include "Battle.h"

void Battle(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster)
{
#pragma region ����
	int turn = 1;
	int burserkerTurn = 0;
	int tauntTurn = 0;
	int armorBreakTurn = 0;
	int barrierBuff = 0;
	int damageUpTurn = 0;
	int choice = 1;
	int monsterChoice = 0;
#pragma endregion

#pragma region ���ͼ���
	cout << "���Ͻô� ���͸� �����ϼ���." << endl;
	cout << "1.�巡��" << endl;
	cin >> monsterChoice;

	switch (monsterChoice)
	{
	case 1:
		monster->SetStat(10000, 500, 50);
		break;
	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}

	cout << "���Ϳ��� ����!" << endl;

#pragma endregion

	while (1)
	{
#pragma region �ൿ����

		if (warrior->GetHp() > 0)
			warrior->SetState(NormalAttack);
		if (mage->GetHp() > 0)
			mage->SetState(NormalAttack);
		if (crusader->GetHp() > 0)
			crusader->SetState(NormalAttack);

		while (choice != 0)
		{
			cout << "���� �� : " << turn << endl;




			PrintBattleInfo(warrior, mage, crusader, monster);

			cout << endl;
			cout << endl;
			cout << "1. ������ �ൿ ����" << endl;
			cout << "2. �������� �ൿ ����" << endl;
			cout << "3. ������� �ൿ ����" << endl;
			cout << "4. �ɷ�ġ ����" << endl;
			cout << "0. ���ÿϷ�" << endl;

			cin >> choice;
			switch (choice)
			{
			case 1:
				Clear();
				if (warrior->GetState() != 5)
				{
					cout << "-------������ �ൿ ����-------" << endl;
					cout << "1. �⺻����" << endl;
					cout << "2. ����Ŀ" << endl;
					cout << "3. ����" << endl;
					cout << "4. �����ı�" << endl;
					cout << "5. ���" << endl;
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
							cout << "Hp�� �����մϴ�." << endl;
						break;

					case 3:
						if (warrior->GetMp() >= 50)
							warrior->SetState(State::Skill2);
						else
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 4:
						if (warrior->GetMp() >= 100)
							warrior->SetState(State::Skill3);
						else
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 5:
						warrior->SetState(State::Meditation);
						break;

					default:
						cout << "�߸��� �Է��Դϴ�." << endl;
						break;
					}
				}
				else if (warrior->GetState() == 5)
				{
					cout << "��������Դϴ�." << endl;
				}
				break;
			case 2:
				Clear();
				if (mage->GetState() != 5)
				{
					cout << "-------�������� �ൿ ����-------" << endl;
					cout << "1. �⺻����" << endl;
					cout << "2. ���̾" << endl;
					cout << "3. ���̾��" << endl;
					cout << "4. ���׿�" << endl;
					cout << "5. ���" << endl;
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
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 3:
						if (mage->GetMp() >= 100)
							mage->SetState(State::Skill2);
						else
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 4:
						if (mage->GetMp() >= 150)
							mage->SetState(State::Skill3);
						else
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 5:
						mage->SetState(State::Meditation);
						break;

					default:
						cout << "�߸��� �Է��Դϴ�." << endl;
						break;
					}
				}
				else if (mage->GetState() == 5)
				{
					cout << "��������Դϴ�." << endl;
				}
				break;
			case 3:
				Clear();
				if (crusader->GetState() != 5)
				{
					cout << "-------������� �ൿ ����-------" << endl;
					cout << "1. �⺻����" << endl;
					cout << "2. ��" << endl;
					cout << "3. �������� ��ȣ��" << endl;
					cout << "4. ������ ����" << endl;
					cout << "5. ���" << endl;
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
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 3:
						if (crusader->GetMp() >= 200)
							crusader->SetState(State::Skill2);
						else
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 4:
						if (crusader->GetMp() >= 100)
							crusader->SetState(State::Skill3);
						else
							cout << "Mp�� �����մϴ�." << endl;
						break;

					case 5:
						crusader->SetState(State::Meditation);
						break;

					default:
						cout << "�߸��� �Է��Դϴ�." << endl;
						Delay();
						break;
					}
				}
				else if (crusader->GetState() == 5)
				{
					cout << "��������Դϴ�." << endl;
					Delay();
				}
				break;
			case 4:
			{

				Clear();
				int lookStat = 0;
				cout << "� ĳ������ ������ ���ðڽ��ϱ�?" << endl;
				cout << "1. ����   2. ������   3. �����" << endl;
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
					cout << "�߸��� �Է��Դϴ�." << endl;
					break;
				}
				break;
			}
			case 0:
				break;
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
			}
			Delay();
			Clear();
		}
		choice = 1;
#pragma endregion


		BuffEnd(warrior, crusader, monster, burserkerTurn, tauntTurn, armorBreakTurn, barrierBuff, damageUpTurn, turn);
		PrintBattleInfo(warrior, mage, crusader, monster);

#pragma region ����
		switch (warrior->GetState())
		{
		case 0:
			cout << "������ ����!" << endl;
			cout << (warrior->GetDamage(damageUpTurn) - monster->GetDef()) << "�� �������� ������." << endl;
			monster->AttackByPlayer(warrior->GetDamage(damageUpTurn));
			break;

		case 1:
			cout << "����Ŀ��ų ���!" << endl;
			if (burserkerTurn == 0)
				warrior->WarriorBuffDebuff(-500, 200, -50);
			else if (burserkerTurn > 0)
				warrior->WarriorBuffDebuff(-500, 0, 0);
			burserkerTurn = turn + 3;
			break;

		case 2:
			cout << "���߽�ų ���!" << endl;
			warrior->PlusMinusMp(-50);
			if (tauntTurn == 0)
				warrior->WarriorBuffDebuff(0, 0, 50);
			tauntTurn = turn + 3;
			break;

		case 3:
			cout << "�����ı� ����!" << endl;
			warrior->PlusMinusMp(-100);
			if (armorBreakTurn == 0)
				monster->MonsterBuffDebuff(0, 0, -50);
			armorBreakTurn = turn + 3;
			cout << (warrior->GetDamage(damageUpTurn) * 1.2f - monster->GetDef()) << "�� �������� ������." << endl;
			monster->AttackByPlayer(warrior->GetDamage(damageUpTurn) * 1.2f);
			break;

		case 4:
			cout << "���" << endl;
			cout << "100�� Mp�� ȸ���߽��ϴ�." << endl;
			warrior->PlusMinusMp(100);
			break;

		case 5:
			cout << "����� ��������Դϴ�." << endl;
			break;

		default:
			break;
		}

		switch (mage->GetState())
		{
		case 0:
			cout << "�������� ����!" << endl;
			cout << (mage->GetDamage(damageUpTurn) - monster->GetDef()) << "�� �������� ������." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn));
			break;

		case 1:
			cout << "���̾ �ߵ�!" << endl;
			mage->PlusMinusMp(-70);
			cout << (mage->GetDamage(damageUpTurn) * 1.5f - monster->GetDef()) << "�� �������� ������." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn) * 1.5f);
			break;

		case 2:
			cout << "���̾�� �ߵ�!" << endl;
			mage->PlusMinusMp(-100);
			cout << (mage->GetDamage(damageUpTurn) * 2 - monster->GetDef()) << "�� �������� ������." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn) * 2);
			break;

		case 3:
			cout << "���׿� �ߵ�!" << endl;
			mage->PlusMinusMp(-200);
			cout << (mage->GetDamage(damageUpTurn) * 3 - monster->GetDef()) << "�� �������� ������." << endl;
			monster->AttackByPlayer(mage->GetDamage(damageUpTurn) * 3);
			break;

		case 4:
			cout << "���" << endl;
			cout << "100�� Mp�� ȸ���߽��ϴ�." << endl;
			mage->PlusMinusMp(100);
			break;

		case 5:
			cout << "������� ��������Դϴ�." << endl;
			break;

		default:
			break;
		}

		switch (crusader->GetState())
		{
		case 0:
			cout << "������� ����!" << endl;
			cout << (crusader->GetDamage(damageUpTurn) - monster->GetDef()) << "�� �������� ������." << endl;
			monster->AttackByPlayer(crusader->GetDamage(damageUpTurn));
			break;

		case 1:
			cout << "�� �ߵ�!" << endl;
			crusader->PlusMinusMp(-80);
			cout << "�Ʊ� ��ü�� " << crusader->GetDamage(damageUpTurn) * 2 << "�� ü���� ȸ���ߴ�." << endl;
			warrior->HealHp(crusader->GetDamage(damageUpTurn) * 2);
			mage->HealHp(crusader->GetDamage(damageUpTurn) * 2);
			crusader->HealHp(crusader->GetDamage(damageUpTurn) * 2);
			break;

		case 2:
			cout << "�������� ��ȣ�� �ߵ�!" << endl;
			crusader->PlusMinusMp(-200);
			barrierBuff = 1;
			break;

		case 3:
			cout << "������ ���� �ߵ�!" << endl;
			crusader->PlusMinusMp(-100);
			damageUpTurn = turn + 3;
			break;

		case 4:
			cout << "���" << endl;
			cout << "100�� Mp�� ȸ���߽��ϴ�." << endl;
			crusader->PlusMinusMp(100);
			break;

		case 5:
			cout << "������ ��������Դϴ�." << endl;
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
			cout << "������ �й��߽��ϴ�." << endl;
			Delay();
			Clear();
			break;
		}
		else if (monster->GetHp() <= 0)
		{
			cout << "������ �¸��߽��ϴ�." << endl;
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
