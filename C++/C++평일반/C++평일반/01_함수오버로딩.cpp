#include <iostream>
using namespace std;

// �Լ�

// �����ε� OverLoading
// ���� �̸��� �Լ��� �ߺ������ϴ°�

// �����ε��� ����
/// �Լ��� �̸��� ���ƾ��Ѵ�!
/// �Ű������� �ڷ����� �ٸ��ų�, ������ �޶���Ѵ�

void Attack(int* hp)
{
	*hp -= 10;
}

void Attack(int* hp, int damage)
{
	*hp -= damage;
}

void Attack(int* hp, int damage, int def)
{
	*hp -= (damage - def);
}

void Attack(int* hp, float damage)
{
	*hp -= (int)damage;
}

int main()
{
	int hp = 100;

	Attack(&hp, 10);

	cout << hp << endl;

	return 0;
}


// ����!
/// ö���� �������� ���α׷�
/// ö���� ���� ���� ���� ������ �Է¹޾�
/// ����, ���(�Ǽ�, ����), �ְ����� �Լ��� ���� �ϼ���!