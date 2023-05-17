#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

// ��� - �л�

// �����ڿ� �Ҹ��ڴ� ����� �Ұ���!
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
	Human() {}
	Human(const char* name, int age, Gender gender)
	{
		strcpy(this->name, name);
		this->age = age;
		this->gender = gender;
	}

	void SetHumanInfo(const char* name, int age, Gender gender)
	{
		strcpy(this->name, name);
		this->age = age;
		this->gender = gender;
	}

	void PrintHumanInfo()
	{
		cout << name << endl;
		cout << age << endl;
		cout << ((gender == Gender::Man) ? "���� " : "����" ) << endl;
	}
};

class Student : public Human
{
private:
	int score;

public:
	Student() : Human() {};
	Student(const char* name, int age, Gender gender, int score)
		:Human(name, age, gender)
	{
		this->score = score;
	}

	void SetStudentInfo(const char* name, int age, Gender gender, int score)
	{
		SetHumanInfo(name, age, gender);
		this->score = score;
	}

	void PrintStudentInfo()
	{
		PrintHumanInfo();
		cout << score << endl;
	}
};

int main()
{
	Student* s1 = new Student();

	s1->SetStudentInfo("���ʵ�", 10, Human::Gender::Man, 100);
	s1->PrintStudentInfo();

	delete s1;
	s1 = nullptr;

	return 0;
}