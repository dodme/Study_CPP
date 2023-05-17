// GameObject - CharacterBase - Gunner
// GameObject - MonsterBase - Slime

// GameObject
/// Vector2
/// �̵�
/// name, �̸� ���� ����
/// Stat
/// Idle - ��� ��¶�
/// Attack
/// Die
/// Gunner�� ������ ���� ���ϴ�.
/// Gunner�� ���� ����
/// ������ ���� ������ ���� ȸ�� ����
/// Slime�� ���� �ݴϴ�.


#include <iostream>
using namespace std;
#pragma warning (disable : 4996)
#include <Windows.h>

typedef unsigned int uint;

struct Vector2
{
	int x;
	int y;

	void SetVector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void MoveVector(int x, int y)
	{
		this->x += x;
		this->y += y;
	}
};

enum State { Idle, Jump, Die, Attack };

class GameObject
{
protected:
	char name[80];
	int hp;
	uint damage;

public:

};

class CharacterBase : public GameObject
{
	
protected:
	State state;
	
	void SetStat(const char* name, int hp, uint damage)
	{
		strcpy(this->name, name);
		this->hp = hp;
		this->damage = damage;
	}
};

class Gunner : public CharacterBase
{
private:

public:
	Gunner(const char* name, int hp, uint damage)
	{
		SetStat(name, hp, damage);
	}

	void PlayerState(State state = Idle)
	{
		this->state = state;
		
		switch (state)
		{
		case Idle:
			cout << "ĳ���Ͱ� �������Դϴ�." << endl;
			break;
		case Jump:
			cout << "ĳ���Ͱ� �����߽��ϴ�." << endl;
			break;
		case Die:
			cout << "ĳ���Ͱ� �׾����ϴ�." << endl;
			break;
		case Attack:
			cout << "ĳ���Ͱ� �����մϴ�." << endl;
			break;
		}
	}

	void PrintPlayerInfo()
	{
		cout << "�̸��� : " << name << endl;
		cout << "ü���� : " << hp << endl;
		cout << "���ݷ��� : " << damage << endl;
	}

	
	void GetAttack(uint damage)
	{
		this->hp -= damage;
	}
	uint GetDamage() { return damage; }

};

class MonsterBase : public GameObject
{
protected:
	State state;

public:
	void SetStat(int hp, uint damage)
	{
		this->hp = hp;
		this->damage = damage;
	}
};

class Slime : public MonsterBase
{
private:

public:
	Slime(int hp, uint damage)
	{
		strcpy(name, "Slime");
		SetStat(hp, damage);
	}

	void MonsterState(State state = Idle)
	{
		this->state = state;
	}

	void PrintMonsterInfo()
	{
		cout << "�̸� : " << name << endl;
		cout << "ü�� : " << hp << endl;
		cout << "���ݷ� : " << damage << endl;
	}

	void GetAttack(uint damage)
	{
		this->hp -= damage;
	}
	uint GetDamage() { return damage; }
};

void Delay()
{
	_sleep(3000);
	system("cls");
}

int Distance(Vector2 v1, Vector2 v2)
{
	return abs(v1.x - v2.x);
}

int main()
{
	char name[80];
	cout << "�÷��̾� �̸��� �Է��ϼ���." << endl;
	cin >> name;

	Gunner* player = new Gunner(name, 1000, 50);
	player->PrintPlayerInfo();

	Vector2 playerVector;
	playerVector.x = 0;
	playerVector.y = 0;

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "���Ͱ� ��Ÿ����!" << endl;

	Slime* slime = new Slime(500, 100);
	slime->PrintMonsterInfo();

	Vector2 monsterVector;
	monsterVector.x = 5;
	monsterVector.y = 0;

	cout << "������ �����մϴ�." << endl;

	Delay();

	int button = 0;
	int distance = Distance(playerVector, monsterVector);

	while (1)
	{
		cout << "�ൿ�� �����ϼ���." << endl;
		cout << "1.���� 2.���� 3.���� 4.���� 5.����" << endl;
		cout << distance << endl;
		cout << "��Ÿ� : 3" << endl;
		cin >> button;

		switch (button)
		{
		case 1:
			playerVector.x += 1;
			cout << "ĳ���Ͱ� ������ 1ĭ �����߽��ϴ�." << endl;
			player->PlayerState(Idle);
			break;

		case 2:
			playerVector.x -= 1;
			cout << "ĳ���Ͱ� �ڷ� 1ĭ �����߽��ϴ�." << endl;
			player->PlayerState(Idle);
			break;

		case 3:
			player->PlayerState(Attack);
			if (distance <= 3)
			{
				slime->GetAttack(player->GetDamage());
			}
			else
			{
				cout << "�Ÿ��� �ʹ� �ٴϴ�." << endl;
			}
			break;

		case 4:
			playerVector.y++;
			player->PlayerState(Jump);
			break;

		case 5:
			cout << "���������� �����ƴ�!" << endl;

			delete player;
			player = nullptr;

			delete slime;
			slime = nullptr;
			return 0;
			
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}


		if (distance <= 1 && (monsterVector.y == playerVector.y))
		{
			
		}
		else if (distance > 1)
		{
			cout << "�������� ������ ���� �ʾҴ�." << endl;
		}
		else if (playerVector.y != 0)
		{
			cout << "�������� ������ ȸ���ߴ�." << endl;
		}

		// �÷��̾� ���� �� ������ ����
		if (playerVector.y != 0)
			playerVector.y--;

		Delay();
	}


	// �����Լ��� ���� �����̷��ߴµ� �ű���� ����...



	delete player;
	player = nullptr;

	delete slime;
	slime = nullptr;


	return 0;
}
