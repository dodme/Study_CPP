#include "Warrior.h"

Warrior::Warrior()
{
	SetStat(2000, 400, 80, 150);
}

void Warrior::PrintWarriorInfo()
{
	cout << "------------------------------------------------------" << endl;
	PrintCharacterInfo();
	cout << "스킬" << endl;
	cout << "1.버서커(Hp소모 500) : 체력500을 소모하여 3턴간 200의 추가공격력을 얻고 방어력은 0이 됩니다." << endl;
	cout << "2.도발(Mp소모 50) : 3턴간 적을 도발하여 50의 방어력을 얻고 공격대상 우선순위가 됩니다." << endl;
	cout << "3.갑옷파괴(Mp소모 100) : 적에게 공격력 X 1.2의 데미지를 입히고 방어를 50만큼 깎습니다." << endl;
	cout << "------------------------------------------------------" << endl;
}

void Warrior::WarriorBuffDebuff(int burserkerHp, int burserkerDamage, int burserkerDef)
{
	hp += burserkerHp;
	damage += burserkerDamage;
	def += burserkerDef;
}
