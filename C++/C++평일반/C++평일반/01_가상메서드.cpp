#include <iostream>
using namespace std;

// 가상메서드 overriding / override
// virtual

// 가상메서드란?
/// > 객체의 메서드 호출당시에 호출기준이 변수의 자료형 기준이었기 때문에
///   정보에 대한 호츨에 제약이 생긴다.
///   따라서 이러한 문제를 타파하기위해 나온 문법

/// > 정의 : 부모에 있는 메서드를 자식클래스에서 재정의 하는것을 기대하는것

// > 메서드 오버라이딩의 조건
/// > 메서드 이름과 매게변수 목록이 일치할것
/// > 부모의 메서드에 virtual이 선언 되어 있을것
/// > 자식클래스 쪽에는 오버라이딩 함수인것을 의미하기위해
///   함수 뒤에 override를 붙여 사용한다

class SampleBase
{
public:
	virtual void Method()
	{
		cout << "Base" << endl;
	}
};

class SampleChild : public SampleBase
{
public:
	void Method() override
	{
		cout << "Child" << endl;
	}
};

int main()
{
	SampleBase* s1 = new SampleChild();

	s1->Method();

	delete s1;
	s1 = nullptr;


	return 0;
}