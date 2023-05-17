#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

class Character
{
protected:
	char name[80];
	char weapon[80];
	
protected:
	void SetCharacterInfo(const char* _name, const char* _weapon)
	{
		strcpy(name, _name);
		strcpy(weapon, _weapon);
	}

	void PrintCharacterInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "무기 : " << weapon << endl;
	}
};

class Warrior : public Character
{
private:
	int def;

public:
	void SetWarriorInfo(const char* _name, const char* _weapon, int _def)
	{
		SetCharacterInfo(_name, _weapon);
		def = _def;
	}

	void PrintWarriorInfo()
	{
		PrintCharacterInfo();
		cout << "방어력 : " << def << endl;
	}
};

class Archer : public Character
{
private:
	int eva;

public:
	void SetArcherInfo(const char* _name, const char* _weapon, int _eva)
	{
		SetCharacterInfo(_name, _weapon);
		eva = _eva;
	}

	void PrintArcherInfo()
	{
		PrintCharacterInfo();
		cout << "회피력 : " << eva << endl;
	}
};

int main()
{
	Warrior* player1 = new Warrior();
	Archer* player2 = new Archer();

	player1->SetWarriorInfo("무한~", "무~야~호~", 10);
	player1->PrintWarriorInfo();

	cout << endl;
	cout << endl;
	cout << endl;

	player2->SetArcherInfo("디즈니", "저작권빔~", 100);
	player2->PrintArcherInfo();

	delete player1;
	player1 = nullptr;
	
	delete player2;
	player2 = nullptr;


	return 0;
}