#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

typedef unsigned int uint;

// 학생의 정보를 가지고있는 클래스
class Student
{
public:
	char name[256];
	uint age;
	uint score;

	void SetStudentInfo(const char* name, uint age, uint score)
	{
		// this 포인터 : 자기자신을 참조하는 포인터
		strcpy(this->name, name);
		this->age = age;
		this->score = score;
	}

	void PrintStudentInfo()
	{
		cout << "이름은 : " << name << endl;
		cout << "나이는 : " << age << endl;
		cout << "성적은 : " << score << endl;
	}
};

int main()
{
	Student* s1 = new Student();

	s1->SetStudentInfo("김민자", 2, 0);
	s1->PrintStudentInfo();

	delete s1;
	s1 = nullptr;

	cout << endl;

	Student* s2 = new Student();

	s2->SetStudentInfo("최목겸", 0, 0);
	s2->PrintStudentInfo();

	delete s2;
	s2 = nullptr;

	return 0;
}

// 문제!
/// Human을 정의 합니다.
/// name, gender, age, stature, weight
/// 헤더파일 쓰세용
/// 클래스로 만드세용
/// Setter 만드세용