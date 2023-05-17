#include <iostream>
using namespace std;

// 순수 가상 메서드
/// > 정의 : 부모에있는 메서드를 자식클래스에서 "반드시!" 재정의 해야 하는것
// virtual 반환형식 함수이름() abstract;
// virtual 반환형식 함수이름() = 0;

// 추상 클래스의 특징
/// > 순수 가상 메서드를 1개 이상 멤버로 가지고 있는 클래스
/// > 인스턴스화가 불가능하다.
/// > 반드시 상속을 통해서만 사용한다.

class SampleBase
{
public:
	virtual void PureMethod() abstract;
	void Print()
	{
		cout << "Hello World!" << endl;
	}
};

class SampleChild : public SampleBase
{
	// SampleBase을(를) 통해 상속됨
	virtual void PureMethod() override
	{
		cout << "재정의 되쪄" << endl;
	}
};

int main()
{
	SampleBase* s1 = new SampleChild();



	return 0;
}