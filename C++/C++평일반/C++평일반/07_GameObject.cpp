// GameObject - CharacterBase - Gunner
// GameObject - MonsterBase - Slime

// GameObject
/// Vector2
/// 이동
/// name, 이름 변경 가능
/// Stat
/// Idle - 대기 라는뜻
/// Attack
/// Die
/// Gunner는 어택중 총을 쏩니다.
/// Gunner는 점프 가능
/// 점프를 통해 슬라임 공격 회피 가능
/// Slime은 총총 뜁니다.


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
			cout << "캐릭터가 대기상태입니다." << endl;
			break;
		case Jump:
			cout << "캐릭터가 점프했습니다." << endl;
			break;
		case Die:
			cout << "캐릭터가 죽었습니다." << endl;
			break;
		case Attack:
			cout << "캐릭터가 공격합니다." << endl;
			break;
		}
	}

	void PrintPlayerInfo()
	{
		cout << "이름은 : " << name << endl;
		cout << "체력은 : " << hp << endl;
		cout << "공격력은 : " << damage << endl;
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
		cout << "이름 : " << name << endl;
		cout << "체력 : " << hp << endl;
		cout << "공격력 : " << damage << endl;
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
	cout << "플레이어 이름을 입력하세요." << endl;
	cin >> name;

	Gunner* player = new Gunner(name, 1000, 50);
	player->PrintPlayerInfo();

	Vector2 playerVector;
	playerVector.x = 0;
	playerVector.y = 0;

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "몬스터가 나타났다!" << endl;

	Slime* slime = new Slime(500, 100);
	slime->PrintMonsterInfo();

	Vector2 monsterVector;
	monsterVector.x = 5;
	monsterVector.y = 0;

	cout << "전투를 시작합니다." << endl;

	Delay();

	int button = 0;
	int distance = Distance(playerVector, monsterVector);

	while (1)
	{
		cout << "행동을 선택하세요." << endl;
		cout << "1.접근 2.후퇴 3.공격 4.점프 5.도망" << endl;
		cout << distance << endl;
		cout << "사거리 : 3" << endl;
		cin >> button;

		switch (button)
		{
		case 1:
			playerVector.x += 1;
			cout << "캐릭터가 앞으로 1칸 전진했습니다." << endl;
			player->PlayerState(Idle);
			break;

		case 2:
			playerVector.x -= 1;
			cout << "캐릭터가 뒤로 1칸 후퇴했습니다." << endl;
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
				cout << "거리가 너무 멉니다." << endl;
			}
			break;

		case 4:
			playerVector.y++;
			player->PlayerState(Jump);
			break;

		case 5:
			cout << "성공적으로 도망쳤다!" << endl;

			delete player;
			player = nullptr;

			delete slime;
			slime = nullptr;
			return 0;
			
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}


		if (distance <= 1 && (monsterVector.y == playerVector.y))
		{
			
		}
		else if (distance > 1)
		{
			cout << "슬라임의 공격이 닿지 않았다." << endl;
		}
		else if (playerVector.y != 0)
		{
			cout << "슬라임의 공격을 회피했다." << endl;
		}

		// 플레이어 점프 후 땅으로 복귀
		if (playerVector.y != 0)
			playerVector.y--;

		Delay();
	}


	// 랜덤함수로 몬스터 움직이려했는데 거기까진 아직...



	delete player;
	player = nullptr;

	delete slime;
	slime = nullptr;


	return 0;
}
