#include "Util.h"

int Random(int maxValue)
{
	return rand() % maxValue + 1;
}

void PrintBattleInfo(Warrior* warrior, Mage* mage, Crusader* crusader, Monster* monster)
{
	cout << "-----------------------------------" << endl;
	cout << "���� HP : " << warrior->GetHp() << endl;
	cout << "������ ���� �ൿ : ";
	switch (warrior->GetState())
	{
	case 0:
		cout << "����" << endl;
		break;
	case 1:
		cout << "����Ŀ" << endl;
		break;
	case 2:
		cout << "����" << endl;
		break;
	case 3:
		cout << "�����ı�" << endl;
		break;
	case 4:
		cout << "���" << endl;
		break;
	case 5:
		cout << "���" << endl;
		break;
	}
	cout << "������ HP : " << mage->GetHp() << endl;
	cout << "�������� ���� �ൿ : ";
	switch (mage->GetState())
	{
	case 0:
		cout << "����" << endl;
		break;
	case 1:
		cout << "���̾" << endl;
		break;
	case 2:
		cout << "���̾��" << endl;
		break;
	case 3:
		cout << "���׿�" << endl;
		break;
	case 4:
		cout << "���" << endl;
		break;
	case 5:
		cout << "���" << endl;
		break;
	}
	cout << "����� HP : " << crusader->GetHp() << endl;
	cout << "������� ���� �ൿ : ";
	switch (crusader->GetState())
	{
	case 0:
		cout << "����" << endl;
		break;
	case 1:
		cout << "��" << endl;
		break;
	case 2:
		cout << "�������� ��ȣ��" << endl;
		break;
	case 3:
		cout << "������ ����" << endl;
		break;
	case 4:
		cout << "���" << endl;
		break;
	case 5:
		cout << "���" << endl;
		break;
	}
	cout << "-----------------------------------" << endl;
	cout << "���� HP : " << monster->GetHp() << endl;
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
