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
		cout << "�̸��� : " << name << endl;
		cout << "����� : " << weapon << endl;
	}
};

class Warrior : public CharacterBase
{
private:
	int def;

public:
	void SetWarriorInfo(const char* name, int def, const char* weapon = "��")
	{
		SetCharacterInfo(name, weapon);
		this->def = def;
	}

	void PrintWarrior()
	{
		PrintCharacterInfo();
		cout << "���� : " << def << endl;
	}
};

class Archer : public CharacterBase
{

private:
	int eva;

public:
	void SetWarriorInfo(const char* name, int eva, const char* weapon = "Ȱ")
	{
		SetCharacterInfo(name, weapon);
		this->eva = eva;
	}

	void PrintWarrior()
	{
		PrintCharacterInfo();
		cout << "ȸ�Ƿ� : " << eva << endl;
	}
};

int main()
{
	Warrior* warrior = new Warrior();

	warrior->SetWarriorInfo("���̹�", 500, "����Į����");
	warrior->PrintWarrior();



	delete warrior;
	warrior = nullptr;

	return 0;
}