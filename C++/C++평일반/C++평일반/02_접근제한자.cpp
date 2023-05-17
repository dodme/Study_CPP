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

private:
	char name[60];
	uint age;
	Gender gender;

public:
	//Setter
	void SetStudentInfo(const char* _name, uint _age, Gender _gender)
	{
		strcpy(name, _name);
		age = _age;
		gender = _gender;
	}
	
	//Getter
	char* GetName() { return name; }
	uint GetAge() { return age; }
	Gender GetGender() { return gender; }
};

int main()
{
	Student* s1 = new Student();

	s1->SetStudentInfo("�����", 3, Student::Gender::Man);

	cout << "�̸��� : " << s1->GetName() << endl;
	cout << "���̴� : " << s1->GetAge() << endl;
	cout << "������ : " << 
		((s1->GetGender() == Student::Gender::Man) ? "����" : "����") << endl;

	delete s1;
	s1 = nullptr;

	return 0;
}