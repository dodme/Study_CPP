#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

class Human
{
public:
	enum Gender
	{
		Man,
		Woman,
	};

protected:
	char name[80];
	int age;
	Gender gender;

public:
	void SetInfo(const char* name, int age, Gender gender)
	{
		strcpy(this->name, name);
		this->age = age;
		this->gender = gender;
	}

	virtual void PrintInfo()
	{
		cout << "�̸��� : " << name << endl;
		cout << "���̴� : " << age << endl;
		cout << "������ : " << ((gender == Gender::Man) ? "����" : "����") << endl;
	}
};

class Student : public Human
{
private:
	int score;

public:
	Student(const char* name, int age, Gender gender, int score)
	{
		SetInfo(name, age, gender);
		this->score = score;
	}

	void PrintInfo() override
	{
		Human::PrintInfo();
		cout << "������ : " << score << endl;
	}
};

int main()
{



	return 0;
}