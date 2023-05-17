#include "Crusader.h"

Crusader::Crusader()
{
	SetStat(1500, 500, 100, 100);
}

void Crusader::PrintCrusaderInfo()
{
	cout << "------------------------------------------------------" << endl;
	PrintCharacterInfo();
	cout << "스킬" << endl;
	cout << "1.힐(Mp소모 80) : 공격력 X 2만큼 아군 전체를 회복한다." << endl;
	cout << "2.성스러운 보호막(Mp소모 200) : 1턴간 아군 전체에게 피해면역 1회를 부여한다." << endl;
	cout << "3.전투의열광(Mp소모 100) : 아군 전체의 공격력을 3턴간 50% 증가시킵니다." << endl;
	cout << "------------------------------------------------------" << endl;
}
