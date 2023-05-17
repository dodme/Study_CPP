#include "MonsterPattern.h"

void DragonPattern(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster, int tauntTurn, int* barrierBuff, int turn)
{
	if ((turn % 5) == 0)
	{
		cout << "���� �𿩵�ϴ�..." << endl;
	}
	else if (((turn % 5) == 1) && (turn != 1))
	{
		cout << "�극��!" << endl;
		if (*barrierBuff == 1)
		{
			*barrierBuff = 0;
			cout << "��ȣ���� ȿ���� �������� ��ȿȭ�ߴ�!" << endl;
		}
		else if (*barrierBuff == 0)
		{
			cout << "�Ʊ� ��ü���� " << monster->GetDamage() * 2 << "�� ������!" << endl;
			warrior->AttackByMonster(monster->GetDamage() * 2);
			mage->AttackByMonster(monster->GetDamage() * 2);
			crusader->AttackByMonster(monster->GetDamage() * 2);

			if (warrior->GetHp() <= 0)
				warrior->SetState(Die);
			if (mage->GetHp() <= 0)
				mage->SetState(Die);
			if (crusader->GetHp() <= 0)
				crusader->SetState(Die);
		}
	}
	else if ((turn % 3) == 0)
	{
		cout << "������ ����!" << endl;
		if (*barrierBuff == 1)
		{
			*barrierBuff = 0;
			cout << "��ȣ���� ȿ���� �������� ��ȿȭ�ߴ�!" << endl;
		}
		else if (*barrierBuff == 0)
		{
			cout << monster->GetDamage() << "�� ������" << endl;
			if (tauntTurn >= turn)
				warrior->AttackByMonster(monster->GetDamage());
			else
			{
				switch (Random(3))
				{
				case 1:
					warrior->AttackByMonster(monster->GetDamage());
					if (warrior->GetHp() <= 0)
						warrior->SetState(Die);
					break;
				case 2:
					mage->AttackByMonster(monster->GetDamage());
					if (mage->GetHp() <= 0)
						mage->SetState(Die);
					break;
				case 3:
					crusader->AttackByMonster(monster->GetDamage());
					if (crusader->GetHp() <= 0)
						crusader->SetState(Die);
					break;
				default:
					break;
				}
			}
		}
	}
	else
	{
		cout << "���ʹ� �ƹ� ������ ����." << endl;
	}
}
