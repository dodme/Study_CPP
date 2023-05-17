#include "MonsterPattern.h"

void DragonPattern(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster, int tauntTurn, int* barrierBuff, int turn)
{
	if ((turn % 5) == 0)
	{
		cout << "빛이 모여듭니다..." << endl;
	}
	else if (((turn % 5) == 1) && (turn != 1))
	{
		cout << "브레스!" << endl;
		if (*barrierBuff == 1)
		{
			*barrierBuff = 0;
			cout << "보호막의 효과로 데미지를 무효화했다!" << endl;
		}
		else if (*barrierBuff == 0)
		{
			cout << "아군 전체에게 " << monster->GetDamage() * 2 << "의 데미지!" << endl;
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
		cout << "몬스터의 공격!" << endl;
		if (*barrierBuff == 1)
		{
			*barrierBuff = 0;
			cout << "보호막의 효과로 데미지를 무효화했다!" << endl;
		}
		else if (*barrierBuff == 0)
		{
			cout << monster->GetDamage() << "의 데미지" << endl;
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
		cout << "몬스터는 아무 반응이 없다." << endl;
	}
}
