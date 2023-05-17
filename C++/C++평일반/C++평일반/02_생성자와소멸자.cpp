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
		cout << "이름은 : " << name << endl;
		cout << "나이는 : " << age << endl;
		cout << "성별은 : " << ((gender == Gender::Man) ? "남자" : "여자") << endl;
	}
};


int main()
{
	Student* s1 = new Student("철수", 10, Student::Gender::Man);

	s1->PrintStudentInfo();

	delete s1;
	s1 = nullptr;

	return 0;
}