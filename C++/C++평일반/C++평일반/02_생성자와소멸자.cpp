#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

typedef unsigned int uint;

class Student
{
//private:
public:
	enum Gender
	{
		Man,
		Woman,
	};

public:
	char name[60];
	uint age;
	Gender gender;

	Student(const char* name, uint age, Gender gender)
	{
		strcpy(this->name, name);
		this->age = age;
		this->gender = gender;
	}

	void PrintStudentInfo() const
	{
		cout << "�̸��� : " << name << endl;
		cout << "���̴� : " << age << endl;
		cout << "������ : " << ((gender == Gender::Man) ? "����" : "����") << endl;
	}
};


int main()
{
	Student* s1 = new Student("ö��", 10, Student::Gender::Man);

	s1->PrintStudentInfo();

	delete s1;
	s1 = nullptr;

	return 0;
}