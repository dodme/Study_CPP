#include <iostream>
using namespace std;

// 상속?
/// > 부모클래스에 있는 정보를 자식클래스에게 물려주는것
// 코드의 생산성, 코드의 재활용성을 높이기위해 사용합니다.

// 부모클래스, 상위클래스, 기초클래스, 기반클래스, 슈퍼클래스, BaseClass
// 자식클래스, 하위클래스, 유도클래스, 파생클래스, 서브클래스, ChildClass

// 부모클래스를 정의 합니다.
class SampleBase
{
public:
	int num;

	void BaseMethod()
	{
		cout << "소라카" << endl;
	}
};

// 자식클래스를 정의합니다.
class SampleChild : public SampleBase
{
public:
	int child_Num;

	void ChildMethod()
	{
		num = 10;
		BaseMethod();
	}
};

int main()
{
	SampleBase* base = new SampleBase();

	// base->ChildMethod(); X

	delete base;
	base = nullptr;

	SampleChild* child = new SampleChild();

	child->BaseMethod();

	delete child;
	child = nullptr;


	return 0;
}