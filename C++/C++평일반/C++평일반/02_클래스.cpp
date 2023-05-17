#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

typedef unsigned int uint;

// �л��� ������ �������ִ� Ŭ����
class Student
{
public:
	char name[256];
	uint age;
	uint score;

	void SetStudentInfo(const char* name, uint age, uint score)
	{
		// this ������ : �ڱ��ڽ��� �����ϴ� ������
		strcpy(this->name, name);
		this->age = age;
		this->score = score;
	}

	void PrintStudentInfo()
	{
		cout << "�̸��� : " << name << endl;
		cout << "���̴� : " << age << endl;
		cout << "������ : " << score << endl;
	}
};

int main()
{
	Student* s1 = new Student();

	s1->SetStudentInfo("�����", 2, 0);
	s1->PrintStudentInfo();

	delete s1;
	s1 = nullptr;

	cout << endl;

	Student* s2 = new Student();

	s2->SetStudentInfo("�ָ��", 0, 0);
	s2->PrintStudentInfo();

	delete s2;
	s2 = nullptr;

	return 0;
}

// ����!
/// Human�� ���� �մϴ�.
/// name, gender, age, stature, weight
/// ������� ������
/// Ŭ������ ���弼��
/// Setter ���弼��