#include "Mage.h"

Mage::Mage()
{
	SetStat(500, 800, 200, 0);
}

void Mage::PrintMageInfo()
{
	cout << "------------------------------------------------------" << endl;
	PrintCharacterInfo();
	cout << "스킬" << endl;
	cout << "1.파이어볼(Mp소모 70) : 공격력 X 1.5의 데미지를 입힙니다." << endl;
	cout << "2.파이어레인(Mp소모 100) : 공격력 X 2의 데미지를 입힙니다." << endl;
	cout << "3.메테오(Mp소모 150) : 공격력 X 3의 데미지를 입힙니다." << endl;
	cout << "------------------------------------------------------" << endl;

}
