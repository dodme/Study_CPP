#include "Warrior.h"

Warrior::Warrior()
{
	SetStat(2000, 400, 80, 150);
}

void Warrior::PrintWarriorInfo()
{
	cout << "------------------------------------------------------" << endl;
	PrintCharacterInfo();
	cout << "��ų" << endl;
	cout << "1.����Ŀ(Hp�Ҹ� 500) : ü��500�� �Ҹ��Ͽ� 3�ϰ� 200�� �߰����ݷ��� ��� ������ 0�� �˴ϴ�." << endl;
	cout << "2.����(Mp�Ҹ� 50) : 3�ϰ� ���� �����Ͽ� 50�� ������ ��� ���ݴ�� �켱������ �˴ϴ�." << endl;
	cout << "3.�����ı�(Mp�Ҹ� 100) : ������ ���ݷ� X 1.2�� �������� ������ �� 50��ŭ ����ϴ�." << endl;
	cout << "------------------------------------------------------" << endl;
}

void Warrior::WarriorBuffDebuff(int burserkerHp, int burserkerDamage, int burserkerDef)
{
	hp += burserkerHp;
	damage += burserkerDamage;
	def += burserkerDef;
}
