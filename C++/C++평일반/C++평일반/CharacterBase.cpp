#include "CharacterBase.h"

void CharacterBase::Movement()
{
	int inputNumber = 0;
	cout << "���� �̵��Ͻðڽ��ϱ�?" << endl;
	cout << "1. ���� 2. ������ 3. ����" << endl;
	cin >> inputNumber;

	switch (inputNumber)
	{
	case 1:
		cout << "�������� �����Դϴ�." << endl;
		vector.x -= stat.moveSpeed;
		break;
	case 2:
		cout << "���������� �����Դϴ�." << endl;
		vector.x += stat.moveSpeed;
		break;
	case 3:
		cout << "�����մϴ�." << endl;
		for (int i = 0; i < stat.jumpSpeed; i++)
		{
			vector.y += 1;
			vector.PrintVector();
			_sleep(500);
		}
		for (int i = 0; i < stat.jumpSpeed; i++)
		{
			vector.y -= 1;
			vector.PrintVector();
			_sleep(500);
		}
		system("cls");
		break;
	default:
		break;
	}
}

void CharacterBase::AttackOrEscape(MonsterBase* monster)
{
	GetTickCount64();
	cout << "� �ൿ�� �Ͻðڽ��ϴ�?" << endl;
	cout << "1. �̵� 2. ���� 3. ����" << endl;
	int inputNumber = 0;
	cin >> inputNumber;
	
	switch (inputNumber)
	{
		GetTickCount64();
	case 1:
		Movement();
		// TODO
		/// ���Ͱ� ĳ���� ���ݽ� ������ ó��

		// Movement()���� ����ó���� �����µ� �Լ� �ۿ��� ��� �����ߴٰ� �޾ƿͼ�
		// ������ ȸ���ؾ����� �𸣰ھ���

		cout << "���Ͱ� �����մϴ�!" << endl;
		SetHp(GetHp() - monster->GetStat().damage);
		cout << "�����" << monster->GetStat().damage << "��ŭ�� ���ظ� �Ծ����ϴ�." << endl;
		cout << "����� ���� ü���� " << stat.hp << "�Դϴ�." << endl;

		return;
	case 2:
		cout << "����� ���͸� �����ϴ�!" << endl;
		monster->SetHp(monster->GetHp() - stat.damage);
		cout << "���Ϳ��� " << stat.damage << "��ŭ ���ظ� �����ϴ�." << endl;
		cout << "���� ������ ü���� " << monster->GetHp() << "�Դϴ�." << endl;

		// TODO 
		/// ������ Ȯ���ݰ�
		if ((rand() % 100 + 1) > 50)
		{
			cout << "���Ͱ� �ݰ��մϴ�!" << endl;
			SetHp(GetHp() - monster->GetStat().damage);
			cout << "���Ϳ���" << monster->GetStat().damage << "��ŭ ���ظ� �Ծ����ϴ�." << endl;
			cout << "����� ���� ü���� " << stat.hp << "�Դϴ�." << endl;
		}


		break;
	case 3:
		cout << "�̺���" << endl;
		return;
	default:
		cout << "���� �ڵ��.." << endl;
		return;
	}

	// TODO
	/// ������ hp�� 0�����ϰ�� MonsterBase �ȿ� Die()ȣ��
	if ((monster->GetHp()) <= 0)
	{
		monster->MonsterDie();
	}

}
