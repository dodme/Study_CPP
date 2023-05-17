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
		cout << "이름은 : " << name << endl;
		cout << "나이는 : " << age << endl;
		cout << "성별은 : " << ((gender == Gender::Man) ? "남자" : "여자") << endl;
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
		cout << "성적은 : " << score << endl;
	}
};

int main()
{



	return 0;
}