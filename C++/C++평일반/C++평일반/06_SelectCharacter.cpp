#include <iostream>
using namespace std;

#pragma warning (disable : 4996)

class CharacterBase
{
protected:
	char name[80];
	char weapon[80];

protected:
	void SetCharacterInfo(const char* name, const char* weapon)
	{
		strcpy(this->name, name);
		strcpy(this->weapon, weapon);
	}

	void PrintCharacterInfo()
	{
		cout << "이름은 : " << name << endl;
		cout << "무기는 : " << weapon << endl;
	}
};

class Warrior : public CharacterBase
{
private:
	int def;

public:
	void SetWarriorInfo(const char* name, int def, const char* weapon = "검")
	{
		SetCharacterInfo(name, weapon);
		this->def = def;
	}

	void PrintWarrior()
	{
		PrintCharacterInfo();
		cout << "방어력 : " << def << endl;
	}
};

class Archer : public CharacterBase
{

private:
	int eva;

public:
	void SetWarriorInfo(const char* name, int eva, const char* weapon = "활")
	{
		SetCharacterInfo(name, weapon);
		this->eva = eva;
	}

	void PrintWarrior()
	{
		PrintCharacterInfo();
		cout << "회피력 : " << eva << endl;
	}
};

int main()
{
	Warrior* warrior = new Warrior();

	warrior->SetWarriorInfo("세이버", 500, "엑스칼리버");
	warrior->PrintWarrior();



	delete warrior;
	warrior = nullptr;

	return 0;
}